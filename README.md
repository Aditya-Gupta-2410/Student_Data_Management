# 🎓 Student Management System

A **console-based Student Management System built in C++** that allows users to add student information, store academic records, display all saved students, and search for a student using their roll number.

This project was created to practice **Object-Oriented Programming (OOP), file handling, vectors, classes, constructors, functions, and menu-driven programming in C++**.

---

## 📌 Features

* ➕ Add new student records
* 👤 Store personal information

  * Roll Number
  * Name
  * Age
  * Gender
  * Address
  * Phone Number
  * Course
* 📚 Store academic information

  * Semester
  * Number of subjects
  * Subject names
  * Marks
* 🧮 Automatically calculate:

  * Total Marks
  * Percentage
  * Grade
* 💾 Save student records permanently in a text file
* 📋 Display all saved student records
* 🔍 Search for a student using Roll Number
* 🖥️ Simple menu-driven console interface

---

## 🛠️ Technologies Used

* **Language:** C++
* **Compiler:** Any standard C++ compiler
* **Libraries:**

  * `iostream`
  * `fstream`
  * `vector`
  * `limits`

---

## 🧠 Concepts Practiced

This project helped me implement and understand several core C++ concepts:

### Object-Oriented Programming

The project is divided into classes to organize different types of information:

* `student` — manages personal student information
* `academic_record` — manages semester, subjects, marks, percentage, and grade
* `student_record` — combines personal and academic information and handles file operations

### Constructors

A parameterized constructor is used to initialize student information.

### Vectors

Vectors are used to dynamically store:

```cpp
vector<string> subjects;
vector<int> marks;
```

The academic vectors are cleared before entering a new student's subjects to prevent previous student data from being carried over.

### File Handling

Student records are stored in:

```text
student_record.txt
```

The program uses:

* `ofstream` to save records
* `ifstream` to read and search records
* `ios::app` to append new records without overwriting existing records

### Input Handling

`getline()` and `cin.ignore()` are used to correctly handle string input containing spaces.

### Menu-Driven Programming

The application provides a simple menu:

```text
1. Add Student
2. Display Student
3. Search Student
4. Exit
```

---

## 📂 Project Structure

```text
Student-Management-System/
│
├── Student_management.cpp
├── student_record.txt
└── README.md
```

> `student_record.txt` is generated/updated by the program when student records are saved.

---

## ⚙️ How to Run

### 1. Clone the repository

```bash
git clone YOUR_REPOSITORY_URL
```

### 2. Open the project

Open `Student_management.cpp` in your preferred C++ IDE or editor.

### 3. Compile

Using g++:

```bash
g++ Student_management.cpp -o Student_management
```

### 4. Run

On Windows:

```bash
Student_management.exe
```

On Linux/macOS:

```bash
./Student_management
```

---

## 🖥️ Program Flow

```text
                 Student Management System
                           │
             ┌─────────────┼─────────────┐
             │             │             │
             ▼             ▼             ▼
        Add Student   Display Records   Search Student
             │             │             │
             ▼             ▼             ▼
      Personal Data   Read Text File   Roll Number
             │
             ▼
      Academic Data
             │
             ▼
     Calculate Result
             │
             ▼
      Save to File
```

---

## 📊 Academic Result Calculation

The program calculates the total marks by adding the marks of all entered subjects.

Percentage is calculated as:

```text
Percentage = Total Marks / Number of Subjects
```

The grading system currently used is:

|   Percentage | Grade |
| -----------: | :---- |
| 95 and above | A+    |
|      85 – 94 | A     |
|      80 – 84 | B+    |
|      70 – 79 | B     |
|     Below 70 | C     |

---

## 💾 Data Storage

Student records are stored in a text file in a structured format.

Example:

```text
=========================================
ROLL NUMBER: 101
NAME: Aditya
AGE: 20
GENDER: Male
ADDRESS: Noida
PHONE: 1234567890
COURSE: BCA

ACADEMIC RECORD
SEMESTER: 3
TOTAL MARKS: 389
PERCENTAGE: 97.25
GRADE: A+
SUBJECTS AND MARKS:
Python : 99
DBMS : 98
Stats : 97
SQL : 95
=========================================
```

---

## 🔍 Searching Records

The search functionality asks for a student's roll number and searches the stored text file.

Example:

```text
Enter Roll Number to search: 101

-------- Student Found --------
ROLL NUMBER: 101
NAME: Aditya
...
```

If the roll number doesn't exist:

```text
------ Student Not Found ------
```

---

## 🚀 Future Improvements

Possible improvements for future versions:

* [ ] Update student records
* [ ] Delete student records
* [ ] Prevent duplicate roll numbers
* [ ] Input validation for age, marks, and phone number
* [ ] Search by student name
* [ ] Sort students by marks or roll number
* [ ] Store data using a database instead of a text file
* [ ] Improve the console UI
* [ ] Add login/authentication
* [ ] Add separate subject-wise result analysis

---

## 🎯 Learning Outcome

Through this project, I practiced building a complete console-based application using C++ rather than writing isolated programs.

The project strengthened my understanding of:

**C++ → OOP → Classes → Vectors → File Handling → Data Processing → Menu-Driven Applications**

---

## 👨‍💻 Author

**Aditya Gupta**

BCA Student | C++ | Python | Data Analytics & AIML

---

⭐ If you find this project useful, consider giving the repository a star!


