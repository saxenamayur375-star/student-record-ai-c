# AI-Assisted Student Record and Result Management System

**Course Code**: PRC1001  
**Course Name**: Programming in C  
**Academic Program**: B.Tech Computer Science and Engineering (Semester I)  
**Institution**: University of Petroleum and Energy Studies (UPES), Dehradun  
**Student Name**: Mayur Saxena  
**SAP ID**: 590032873  
**Roll No.**: R214226001  
**Repository**: [saxenamayur375-star/student-record-ai-c](https://github.com/saxenamayur375-star/student-record-ai-c)  

---

## 📖 Table of Contents
1. [Project Overview](#-project-overview)
2. [Key Features](#-key-features)
   - [Part A: Core C Requirements](#part-a--core-c-requirements)
   - [Part B: AI-Assisted Academic Advisor](#part-b--ai-assisted-academic-advisor)
3. [Data Structures & Design](#-data-structures--design)
4. [Compilation & Execution Instructions](#-compilation--execution-instructions)
5. [Menu Navigation & Usage Guide](#-menu-navigation--usage-guide)
6. [Academic Advisor Logic & Decision Matrix](#-academic-advisor-logic--decision-matrix)
7. [Testing & Verification](#-testing--verification)
8. [GitHub Workflow & Commit History](#-github-workflow--commit-history)
9. [Viva Preparation & Concept Summary](#-viva-preparation--concept-summary)

---

## 📌 Project Overview
The **AI-Assisted Student Record and Result Management System** is a robust console-based, menu-driven software application written in standard C. Developed as a semester project for **PRC1001 (Programming in C)**, it bridges fundamental C constructs—structures, arrays, loops, string operations, sorting algorithms, and modular functions—with modern software development practices including Git version control, GitHub issue tracking, and an AI-assisted heuristic Academic Advisor module.

---

## 🎯 Key Features

### Part A – Core C Requirements
1. **Menu-Driven Interface**: Clean, looped console UI providing seamless user access to 9 distinct functional options and a safe exit.
2. **Preloaded Baseline Records**: Program initializes with 5 verified student profiles covering all 4 academic years (1st, 2nd, 3rd, and 4th years).
3. **Record Storage**: Comprehensive data tracking for each student:
   - `SAP ID` (Unique 9-digit `long int`)
   - `Roll No.` (String alphanumeric identifier)
   - `Name` (Full name string, supporting whitespace)
   - `Phone No.` (Contact string)
   - `Email ID` (Official university email string)
   - `Year` (Integer 1 to 4)
   - `Semester` (Integer 1 to 8)
   - `SGPA Array` (`float[8]` storing Semester Grade Point Averages; `0.0` for upcoming semesters)
   - `CGPA` (Calculated cumulative grade point average)
4. **Student Record Operations**:
   - **Add Student**: Interactive data entry with automated duplication checks against existing SAP IDs and input bounding.
   - **Search Record**: Fast linear search by SAP ID displaying complete student profile and semester breakdown.
   - **Delete Record**: Deletes an existing record by SAP ID and shifts subsequent array elements leftward to maintain continuous memory.
   - **Display All Records**: Formatted, card-style breakdown of all enrolled student records.
5. **Analytics & Sorting**:
   - **CGPA Calculation**: Computes dynamic average based solely on completed semesters (`sgpa > 0.0`), preventing artificial score deflation for junior students.
   - **Cohort Analysis (Year-wise Average CGPA)**: Aggregates performance by academic year (1st through 4th) to analyze batch trends.
   - **Sort by SAP ID**: Bubble sort arranging records in ascending order of SAP ID on a copied array (preserving primary entry order).
   - **Sort by Name**: Alphabetical ascending bubble sort using `strcmp()` on a copied array.

### Part B – AI-Assisted Academic Advisor
- Employs a heuristic decision-making engine in C suggested and refined using AI tools.
- Evaluates student CGPA against 4 defined performance tiers.
- Performs diagnostic analysis by looping across semester SGPAs to identify the specific lowest-scoring semester and generate actionable counsel.
- Offers dual execution: single student lookup or comprehensive whole-class advisory report.

---

## 🏗 Data Structures & Design

```c
#define MAX_STUDENTS 100
#define TOTAL_SEMESTERS 8

struct Student {
    long int sap_id;             /* Unique student identifier */
    char roll_no[20];            /* Alphanumeric roll number */
    char name[50];               /* Full student name */
    char phone[15];              /* Contact phone number */
    char email[50];              /* Email address */
    int year;                    /* Current academic year (1-4) */
    int semester;                /* Current semester (1-8) */
    float sgpa[TOTAL_SEMESTERS]; /* SGPA history for up to 8 terms */
    float cgpa;                  /* Cumulative Grade Point Average */
};

/* Database array */
struct Student students[MAX_STUDENTS];
int student_count = 0;
```

---

## ⚙️ Compilation & Execution Instructions

### Prerequisites
- GCC Compiler (MinGW / TDM-GCC / GCC on Linux / Clang on macOS)

### 1. Compile the Program
Open a terminal (PowerShell, Command Prompt, or Bash) in the project directory:

```bash
gcc -Wall -Wextra 590032873.c -o 590032873.exe
```

### 2. Run the Program
On Windows:
```cmd
590032873.exe
```
On Linux / macOS:
```bash
./590032873.exe
```

### 3. Automated Regression Test
Run the pre-configured test suite using input redirection:
```powershell
Get-Content .\tests\sample_input.txt | .\590032873.exe
```

---

## 🧭 Menu Navigation & Usage Guide

```
------------------------- MAIN MENU -------------------------
1. Add Student Details
2. Search and Display a Student Record
3. Calculate CGPA of Each Student
4. Calculate Average CGPA of Students by Year
5. Display Records of All Students
6. Delete an Individual Student Record
7. Display All Records in Increasing Order of SAP ID
8. Display All Records in Increasing Order of Name
9. AI-Assisted Academic Advisor
0. Exit
-------------------------------------------------------------
```

---

## 🧠 Academic Advisor Logic & Decision Matrix

| Performance Category | CGPA Range | Program Recommendation | Personalized Note |
| :--- | :---: | :--- | :--- |
| **Excellent Performance** | $\ge 8.50$ | Maintain current study patterns, engage in competitive coding, research, and technical internships. | Highlights lowest semester SGPA for maintaining perfection. |
| **Good Performance** | $7.00 - 8.49$ | Maintain consistency, focus on core computer science subjects, and revise lecture notes to cross the 8.5 threshold. | Identifies specific semester to target for improvement. |
| **Needs Improvement** | $5.50 - 6.99$ | Allocate additional study hours to weaker subjects and solve past-year examination papers before mid-terms. | Pinpoints lowest recorded SGPA semester for remedial focus. |
| **Requires Immediate Attention** | $< 5.50$ | Meet faculty academic advisor promptly, attend remedial doubt sessions, and rebuild foundational concepts. | Flags lowest scoring semester for urgent intervention. |

---

## 🧪 Testing & Verification
The `tests/` directory contains complete input and output captures:
- `tests/sample_input.txt`: Streamlined command sequence covering all menu options, edge cases, student insertion, record deletion, and advisor reporting.
- `tests/sample_output.txt`: Exact terminal output verifying successful execution, zero errors, and clean menu responses.

---

## 🐙 GitHub Workflow & Commit History

In compliance with project specifications, four distinct commits were created reflecting progressive development milestones:

| Commit # | Commit Hash | Message / Milestone Description |
| :---: | :---: | :--- |
| **1** | `0cd42d8` | **Initial C program**: Defined `struct Student`, constants, global array, sample student loader, and initial menu skeleton. |
| **2** | `f96b5e7` | **Student record functions**: Implemented `addStudent()`, `searchStudent()`, `deleteStudent()`, and detailed record display. |
| **3** | `55fae85` | **Sorting & CGPA functions**: Implemented `calculateCGPA()`, `averageCGPAByYear()`, and bubble sorting by SAP ID and Name. Closed Issue #1. |
| **4** | `*latest*` | **AI-assisted advisor + documentation**: Implemented Academic Advisor heuristic engine, created `AI_USAGE_LOG.md`, test cases, and comprehensive README. |

### GitHub Issue Tracking
- **Issue #1**: *"Implement CGPA calculation and sorting algorithms"*
  - **State**: Closed / Completed
  - **Reference**: Resolved in Commit `55fae85` with full verification.

---

## 🎓 Viva Preparation & Concept Summary

During the laboratory viva, be prepared to explain:
1. **Dynamic CGPA Calculation**: Why we iterate over `sgpa[i] > 0.0f` rather than dividing by 8 (which would falsely penalize students in earlier semesters who have not completed all 8 terms).
2. **Preservation of Original Data in Sorting**: Why records are copied to `temp_list` before running Bubble Sort (so the user's primary database ordering and record indices remain undisturbed).
3. **Memory Management during Deletion**: How deleting record index `k` uses a sequential shift `students[j] = students[j + 1]` up to `student_count - 1` and decrements `student_count`.
4. **AI Advisor Heuristics**: How AI was used to establish realistic GPA thresholds and how that guidance was codified into native C conditional blocks (`if-else` ladder).
