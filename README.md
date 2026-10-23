# Student Record Management System in C

A beginner-friendly **Student Record Management System** developed in C using a **singly linked list** and **file handling**.

This project was created to apply the C programming and Data Structures concepts I have been learning by building a practical application.

## 📌 Features

* Add student records
* Display all student records
* Search students by ID
* Update student details
* Delete student records by ID
* Count total number of students
* Sort students by ID
* Prevent duplicate student IDs
* Dynamic memory allocation using `malloc()` and `free()`
* Save student records to a file
* Load previously saved records when the program starts

## 🧠 Concepts Used

* Structures
* Pointers
* Singly Linked Lists
* Dynamic Memory Allocation
* Functions
* Searching
* Sorting
* File Handling
* CRUD Operations

## 💾 File Persistence

The project uses `students.txt` to store student records.

When the program starts, previously saved records are loaded from the file into the linked list.

Whenever a student is added, updated, deleted, or the records are sorted, the current data is saved back to the file.

## ▶️ How to Run

### 1. Clone the repository

```bash
git clone https://github.com/pandavasonu828-tech/student-record-management-system-c.git
```

### 2. Open the project folder

```bash
cd student-record-management-system-c
```

### 3. Compile the C program

```bash
gcc STUDENT_RECORD_MANAGEMENT_SYSTEM.c -o student
```

### 4. Run the program

On Windows:

```bash
student.exe
```

## 📂 Project Files

```text
student-record-management-system-c/
│
├── STUDENT_RECORD_MANAGEMENT_SYSTEM.c
├── students.txt
└── README.md
```

## 🚀 Future Improvements

Some improvements I would like to explore in future versions:

* Support student names containing spaces
* Improve input validation
* Add more advanced searching and sorting options
* Improve the user interface
* Separate the project into multiple C source and header files

## 🎯 Learning Objective

The main purpose of this project was to understand how **C programming concepts and Data Structures can be combined to build a practical application**.

This project helped me practice linked lists, pointers, dynamic memory allocation, CRUD operations, sorting, and file handling in a single project.
