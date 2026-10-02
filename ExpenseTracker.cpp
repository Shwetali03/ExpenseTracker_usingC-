#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Expense
{
public:
    int id;
    string category;
    string description;
    double amount;

    void display() const
    {
        cout << "\nID          : " << id;
        cout << "\nCategory    : " << category;
        cout << "\nDescription : " << description;
        cout << "\nAmount      : Rs. " << fixed << setprecision(2) << amount << endl;
    }
};

class ExpenseTracker
{
private:
    vector<Expense> expenses;
    const string fileName = "expenses.txt";

    void saveToFile()
    {
        ofstream file(fileName);

        if (!file)
        {
            cout << "Error: Unable to open file.\n";
            return;
        }

        for (const Expense &e : expenses)
        {
            file << e.id << "|"
                 << e.category << "|"
                 << e.description << "|"
                 << e.amount << endl;
        }

        file.close();
    }

    void loadFromFile()
    {
        ifstream file(fileName);

        if (!file)
            return;

        string line;

        while (getline(file, line))
        {
            size_t p1 = line.find("|");
            size_t p2 = line.find("|", p1 + 1);
            size_t p3 = line.find("|", p2 + 1);

            if (p1 == string::npos ||
                p2 == string::npos ||
                p3 == string::npos)
            {
                continue;
            }

            Expense e;

            try
            {
                e.id = stoi(line.substr(0, p1));

                e.category = line.substr(
                    p1 + 1,
                    p2 - p1 - 1
                );

                e.description = line.substr(
                    p2 + 1,
                    p3 - p2 - 1
                );

                e.amount = stod(line.substr(p3 + 1));

                expenses.push_back(e);
            }
            catch (...)
            {
                cout << "Invalid record skipped.\n";
            }
        }

        file.close();
    }

    int findExpense(int id)
    {
        for (int i = 0; i < expenses.size(); i++)
        {
            if (expenses[i].id == id)
                return i;
        }

        return -1;
    }

public:

    ExpenseTracker()
    {
        loadFromFile();
    }

    void addExpense()
    {
        Expense e;

        cout << "\nEnter Expense ID: ";
        cin >> e.id;

        if (findExpense(e.id) != -1)
        {
            cout << "This ID already exists.\n";
            return;
        }

        cin.ignore();

        cout << "Enter Category: ";
        getline(cin, e.category);

        cout << "Enter Description: ";
        getline(cin, e.description);

        cout << "Enter Amount: ";
        cin >> e.amount;

        if (e.amount < 0)
        {
            cout << "Amount cannot be negative.\n";
            return;
        }

        expenses.push_back(e);

        saveToFile();

        cout << "\nExpense added successfully!\n";
    }

    void viewExpenses() const
    {
        if (expenses.empty())
        {
            cout << "\nNo expenses found.\n";
            return;
        }

        cout << "\n========== ALL EXPENSES ==========\n";

        for (const Expense &e : expenses)
        {
            e.display();

            cout << "--------------------------------\n";
        }
    }

    void searchExpense()
    {
        int id;

        cout << "\nEnter Expense ID: ";
        cin >> id;

        int index = findExpense(id);

        if (index == -1)
        {
            cout << "\nExpense not found.\n";
            return;
        }

        cout << "\n========== EXPENSE FOUND ==========\n";

        expenses[index].display();
    }

    void deleteExpense()
    {
        int id;

        cout << "\nEnter Expense ID to delete: ";
        cin >> id;

        int index = findExpense(id);

        if (index == -1)
        {
            cout << "\nExpense not found.\n";
            return;
        }

        expenses.erase(expenses.begin() + index);

        saveToFile();

        cout << "\nExpense deleted successfully!\n";
    }

    void calculateTotal() const
    {
        double total = 0;

        for (const Expense &e : expenses)
        {
            total += e.amount;
        }

        cout << fixed << setprecision(2);
        cout << "\nTotal Expense = Rs. " << total << endl;
    }

    void showMenu()
    {
        int choice;

        do
        {
            cout << "\n\n========== EXPENSE TRACKER ==========\n";
            cout << "1. Add Expense\n";
            cout << "2. View All Expenses\n";
            cout << "3. Search Expense\n";
            cout << "4. Delete Expense\n";
            cout << "5. Calculate Total Expense\n";
            cout << "6. Exit\n";

            cout << "\nEnter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                addExpense();
                break;

            case 2:
                viewExpenses();
                break;

            case 3:
                searchExpense();
                break;

            case 4:
                deleteExpense();
                break;

            case 5:
                calculateTotal();
                break;

            case 6:
                cout << "\nThank you for using Expense Tracker!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
            }

        } while (choice != 6);
    }
};

int main()
{
    ExpenseTracker tracker;

    tracker.showMenu();

    return 0;
}