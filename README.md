# 💰 C++ Expense Tracker

A simple console-based **Expense Tracker** developed using C++.
The project allows users to add, view, search, delete, and calculate expenses with data stored using file handling.

## 🚀 Features

* ➕ Add Expense
* 📋 View All Expenses
* 🔍 Search Expense by ID
* 🗑️ Delete Expense
* 💰 Calculate Total Expenses
* 💾 Store expenses permanently using file handling
* ✅ Prevent duplicate Expense IDs

## 🛠️ Technologies Used

* **C++**
* **Object-Oriented Programming (OOP)**
* **STL Vector**
* **File Handling**
* **VS Code**

## 📚 C++ Concepts Used

* Classes and Objects
* Functions
* Encapsulation
* Vectors
* Strings
* File Input/Output
* Loops
* Conditional Statements
* Switch Case

## 📂 Project Structure

```text
cpp-expense-tracker/
│
├── main.cpp
├── expenses.txt
├── README.md
└── .gitignore
```

## ▶️ How to Run

### 1. Clone the repository

```bash
git clone https://github.com/your-username/cpp-expense-tracker.git
```

### 2. Open the project

Open the project folder in **VS Code**.

### 3. Compile the program

```bash
g++ main.cpp -o ExpenseTracker
```

### 4. Run the program

**Windows:**

```bash
.\ExpenseTracker
```

**Linux/macOS:**

```bash
./ExpenseTracker
```

## 🖥️ Sample Output

```text
========== EXPENSE TRACKER ==========
1. Add Expense
2. View All Expenses
3. Search Expense
4. Delete Expense
5. Calculate Total Expense
6. Exit

Enter your choice: 1

Enter Expense ID: 1
Enter Category: Food
Enter Description: Lunch
Enter Amount: 150

Expense added successfully!
```

### View Expenses

```text
========== ALL EXPENSES ==========

ID          : 1
Category    : Food
Description : Lunch
Amount      : Rs. 150.00
--------------------------------

ID          : 2
Category    : Travel
Description : Bus Ticket
Amount      : Rs. 80.00
--------------------------------
```

### Total Expense

```text
Total Expense = Rs. 230.00
```

## 💾 Data Storage

The expenses are stored in `expenses.txt`.

Example:

```text
1|Food|Lunch|150
2|Travel|Bus Ticket|80
```

The program loads existing expenses when it starts and saves changes automatically.

## 🔮 Future Improvements

* Add expense date
* Add category-wise expense summary
* Add monthly expense tracking
* Add edit/update expense option
* Add graphical user interface
* Add income and balance tracking

## 👩‍💻 Author

**Shwetali Bhalkar**

---

⭐ If you found this project useful, consider giving the repository a star!
