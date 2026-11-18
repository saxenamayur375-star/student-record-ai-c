/*
 * Project Title : AI-Assisted Student Record and Result Management System
 * Course Name   : Programming in C (PRC1001)
 * Program       : B.Tech CSE (Semester I)
 * Student Name  : Mayur Saxena
 * SAP ID        : 590032873
 * Description   : Added CGPA calculation, year-wise average CGPA reporting,
 *                 and sorting by SAP ID and Name using Bubble Sort.
 */

#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define TOTAL_SEMESTERS 8

/* Structure to store individual student details */
struct Student {
    long int sap_id;
    char roll_no[20];
    char name[50];
    char phone[15];
    char email[50];
    int year;                    /* 1, 2, 3, or 4 */
    int semester;                /* 1 to 8 */
    float sgpa[TOTAL_SEMESTERS]; /* SGPA for all 8 semesters (0.0 if upcoming) */
    float cgpa;
};

/* Global array of student records and counter */
struct Student students[MAX_STUDENTS];
int student_count = 0;

/* Function prototypes */
void calculateCGPA(struct Student *s);
void calculateAllCGPA();
void averageCGPAByYear();
void displaySortedBySapId();
void displaySortedByName();
void loadSampleStudents();
void addStudent();
void searchStudent();
void deleteStudent();
void displayOneStudent(struct Student s);
void displayAllStudents();

/* Calculate CGPA of an individual student by averaging completed (> 0.0) SGPAs */
void calculateCGPA(struct Student *s) {
    float sum = 0.0f;
    int completed_sems = 0;
    int i;

    for (i = 0; i < TOTAL_SEMESTERS; i++) {
        if (s->sgpa[i] > 0.0f) {
            sum += s->sgpa[i];
            completed_sems++;
        }
    }

    if (completed_sems > 0) {
        s->cgpa = sum / completed_sems;
    } else {
        s->cgpa = 0.0f;
    }
}

/* Recalculate and display CGPA summary table for all students */
void calculateAllCGPA() {
    int i;
    if (student_count == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n--- CGPA Calculation for All Students ---\n");
    printf("%-12s %-22s %-6s %-6s %-8s\n", "SAP ID", "Name", "Year", "Sem", "CGPA");
    printf("------------------------------------------------------------\n");

    for (i = 0; i < student_count; i++) {
        calculateCGPA(&students[i]);
        printf("%-12ld %-22s %-6d %-6d %-8.2f\n",
               students[i].sap_id,
               students[i].name,
               students[i].year,
               students[i].semester,
               students[i].cgpa);
    }
}

/* Calculate average CGPA of students belonging to each academic year */
void averageCGPAByYear() {
    int yr, i, count_in_year;
    float sum_cgpa;

    if (student_count == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n--- Year-wise Average CGPA Report ---\n");
    for (yr = 1; yr <= 4; yr++) {
        sum_cgpa = 0.0f;
        count_in_year = 0;

        for (i = 0; i < student_count; i++) {
            if (students[i].year == yr) {
                sum_cgpa += students[i].cgpa;
                count_in_year++;
            }
        }

        if (count_in_year > 0) {
            printf("Year %d : %d student(s) | Average CGPA = %.2f\n",
                   yr, count_in_year, sum_cgpa / count_in_year);
        } else {
            printf("Year %d : 0 students   | Average CGPA = N/A\n", yr);
        }
    }
}

/* Display all student records in increasing order of SAP ID using Bubble Sort */
void displaySortedBySapId() {
    struct Student temp_list[MAX_STUDENTS];
    struct Student swap_temp;
    int i, j;

    if (student_count == 0) {
        printf("\nNo student records to sort.\n");
        return;
    }

    /* Copy into temporary array to keep original collection intact */
    for (i = 0; i < student_count; i++) {
        temp_list[i] = students[i];
    }

    /* Bubble Sort by SAP ID (Ascending) */
    for (i = 0; i < student_count - 1; i++) {
        for (j = 0; j < student_count - i - 1; j++) {
            if (temp_list[j].sap_id > temp_list[j + 1].sap_id) {
                swap_temp = temp_list[j];
                temp_list[j] = temp_list[j + 1];
                temp_list[j + 1] = swap_temp;
            }
        }
    }

    printf("\n--- Student Records in Increasing Order of SAP ID ---\n");
    printf("%-12s %-14s %-22s %-6s %-6s %-8s\n",
           "SAP ID", "Roll No.", "Name", "Year", "Sem", "CGPA");
    printf("------------------------------------------------------------------------\n");
    for (i = 0; i < student_count; i++) {
        printf("%-12ld %-14s %-22s %-6d %-6d %-8.2f\n",
               temp_list[i].sap_id,
               temp_list[i].roll_no,
               temp_list[i].name,
               temp_list[i].year,
               temp_list[i].semester,
               temp_list[i].cgpa);
    }
}

/* Display all student records in increasing alphabetical order of Name using Bubble Sort */
void displaySortedByName() {
    struct Student temp_list[MAX_STUDENTS];
    struct Student swap_temp;
    int i, j;

    if (student_count == 0) {
        printf("\nNo student records to sort.\n");
        return;
    }

    for (i = 0; i < student_count; i++) {
        temp_list[i] = students[i];
    }

    /* Bubble Sort by Name alphabetically (Ascending) */
    for (i = 0; i < student_count - 1; i++) {
        for (j = 0; j < student_count - i - 1; j++) {
            if (strcmp(temp_list[j].name, temp_list[j + 1].name) > 0) {
                swap_temp = temp_list[j];
                temp_list[j] = temp_list[j + 1];
                temp_list[j + 1] = swap_temp;
            }
        }
    }

    printf("\n--- Student Records in Increasing Order of Name ---\n");
    printf("%-22s %-12s %-14s %-6s %-6s %-8s\n",
           "Name", "SAP ID", "Roll No.", "Year", "Sem", "CGPA");
    printf("------------------------------------------------------------------------\n");
    for (i = 0; i < student_count; i++) {
        printf("%-22s %-12ld %-14s %-6d %-6d %-8.2f\n",
               temp_list[i].name,
               temp_list[i].sap_id,
               temp_list[i].roll_no,
               temp_list[i].year,
               temp_list[i].semester,
               temp_list[i].cgpa);
    }
}

/* Pre-load initial sample records */
void loadSampleStudents() {
    int i;

    /* Student 1: 1st Year (Mayur Saxena) */
    students[0].sap_id = 590032873;
    strcpy(students[0].roll_no, "R214226001");
    strcpy(students[0].name, "Mayur Saxena");
    strcpy(students[0].phone, "9876543210");
    strcpy(students[0].email, "mayur.saxena@stu.upes.ac.in");
    students[0].year = 1;
    students[0].semester = 1;
    float s0[8] = {9.15f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    for (i = 0; i < 8; i++) students[0].sgpa[i] = s0[i];
    calculateCGPA(&students[0]);

    /* Student 2: 2nd Year */
    students[1].sap_id = 50010102;
    strcpy(students[1].roll_no, "R214225002");
    strcpy(students[1].name, "Priya Verma");
    strcpy(students[1].phone, "9812345670");
    strcpy(students[1].email, "priya.verma@stu.upes.ac.in");
    students[1].year = 2;
    students[1].semester = 3;
    float s1[8] = {7.60f, 7.90f, 8.05f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    for (i = 0; i < 8; i++) students[1].sgpa[i] = s1[i];
    calculateCGPA(&students[1]);

    /* Student 3: 3rd Year */
    students[2].sap_id = 50010108;
    strcpy(students[2].roll_no, "R214224008");
    strcpy(students[2].name, "Rohan Negi");
    strcpy(students[2].phone, "9765432109");
    strcpy(students[2].email, "rohan.negi@stu.upes.ac.in");
    students[2].year = 3;
    students[2].semester = 5;
    float s2[8] = {6.50f, 6.20f, 5.90f, 6.40f, 6.25f, 0.0f, 0.0f, 0.0f};
    for (i = 0; i < 8; i++) students[2].sgpa[i] = s2[i];
    calculateCGPA(&students[2]);

    /* Student 4: 2nd Year */
    students[3].sap_id = 50010101;
    strcpy(students[3].roll_no, "R214225001");
    strcpy(students[3].name, "Karan Bisht");
    strcpy(students[3].phone, "9654321098");
    strcpy(students[3].email, "karan.bisht@stu.upes.ac.in");
    students[3].year = 2;
    students[3].semester = 4;
    float s3[8] = {5.40f, 4.90f, 5.10f, 5.00f, 0.0f, 0.0f, 0.0f, 0.0f};
    for (i = 0; i < 8; i++) students[3].sgpa[i] = s3[i];
    calculateCGPA(&students[3]);

    /* Student 5: 4th Year */
    students[4].sap_id = 50010104;
    strcpy(students[4].roll_no, "R214223004");
    strcpy(students[4].name, "Neha Rawat");
    strcpy(students[4].phone, "9543210987");
    strcpy(students[4].email, "neha.rawat@stu.upes.ac.in");
    students[4].year = 4;
    students[4].semester = 7;
    float s4[8] = {8.50f, 8.70f, 8.90f, 8.60f, 8.80f, 9.00f, 8.95f, 0.0f};
    for (i = 0; i < 8; i++) students[4].sgpa[i] = s4[i];
    calculateCGPA(&students[4]);

    student_count = 5;
}

/* Function to add a new student record */
void addStudent() {
    struct Student s;
    int i;

    if (student_count >= MAX_STUDENTS) {
        printf("\n[Error] Database limit reached (%d students). Cannot add more.\n", MAX_STUDENTS);
        return;
    }

    printf("\n--- Add New Student Record ---\n");
    printf("Enter SAP ID: ");
    scanf("%ld", &s.sap_id);

    /* Check for duplicate SAP ID */
    for (i = 0; i < student_count; i++) {
        if (students[i].sap_id == s.sap_id) {
            printf("[Error] Student with SAP ID %ld already exists in the system!\n", s.sap_id);
            return;
        }
    }

    printf("Enter Roll No.: ");
    scanf(" %19s", s.roll_no);

    printf("Enter Full Name: ");
    scanf(" %49[^\n]", s.name);

    printf("Enter Phone No.: ");
    scanf(" %14s", s.phone);

    printf("Enter Email ID: ");
    scanf(" %49s", s.email);

    printf("Enter Year (1 to 4): ");
    scanf("%d", &s.year);

    printf("Enter Current Semester (1 to 8): ");
    scanf("%d", &s.semester);

    printf("Enter SGPA for all 8 semesters (enter 0 for upcoming semesters):\n");
    for (i = 0; i < TOTAL_SEMESTERS; i++) {
        printf("  Semester %d SGPA: ", i + 1);
        scanf("%f", &s.sgpa[i]);
    }

    calculateCGPA(&s);
    students[student_count] = s;
    student_count++;

    printf("\n[Success] Student '%s' (SAP ID: %ld) added successfully with CGPA: %.2f\n",
           s.name, s.sap_id, s.cgpa);
}

/* Helper function to display detailed record of one student */
void displayOneStudent(struct Student s) {
    int i;
    printf("SAP ID    : %ld\n", s.sap_id);
    printf("Roll No.  : %s\n", s.roll_no);
    printf("Name      : %s\n", s.name);
    printf("Phone No. : %s\n", s.phone);
    printf("Email ID  : %s\n", s.email);
    printf("Year      : %d\n", s.year);
    printf("Semester  : %d\n", s.semester);
    printf("SGPA (1-8): ");
    for (i = 0; i < TOTAL_SEMESTERS; i++) {
        if (s.sgpa[i] > 0.0f) {
            printf("S%d:%.2f ", i + 1, s.sgpa[i]);
        } else {
            printf("S%d:NA ", i + 1);
        }
    }
    printf("\nCGPA      : %.2f\n", s.cgpa);
}

/* Function to search and display a student record by SAP ID */
void searchStudent() {
    long int target_sap;
    int i, found = 0;

    if (student_count == 0) {
        printf("\nNo student records available to search.\n");
        return;
    }

    printf("\nEnter SAP ID to search: ");
    scanf("%ld", &target_sap);

    for (i = 0; i < student_count; i++) {
        if (students[i].sap_id == target_sap) {
            printf("\n--- Student Record Found ---\n");
            displayOneStudent(students[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\n[Notice] Student with SAP ID %ld was not found.\n", target_sap);
    }
}

/* Function to delete an individual student record by SAP ID */
void deleteStudent() {
    long int target_sap;
    int i, j, found_index = -1;

    if (student_count == 0) {
        printf("\nNo student records available to delete.\n");
        return;
    }

    printf("\nEnter SAP ID of the student to delete: ");
    scanf("%ld", &target_sap);

    for (i = 0; i < student_count; i++) {
        if (students[i].sap_id == target_sap) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        printf("\n[Error] Student with SAP ID %ld not found. Deletion aborted.\n", target_sap);
        return;
    }

    printf("\nDeleting record of '%s' (SAP ID: %ld)...\n",
           students[found_index].name, students[found_index].sap_id);

    /* Shift subsequent records to fill deleted slot */
    for (j = found_index; j < student_count - 1; j++) {
        students[j] = students[j + 1];
    }
    student_count--;

    printf("[Success] Record deleted. Total students remaining: %d\n", student_count);
}

/* Function to display all student records */
void displayAllStudents() {
    int i;
    if (student_count == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n================ ALL STUDENT RECORDS (Total: %d) ================\n", student_count);
    for (i = 0; i < student_count; i++) {
        printf("\n[Record #%d]\n", i + 1);
        displayOneStudent(students[i]);
    }
    printf("=================================================================\n");
}

int main() {
    int choice;
    loadSampleStudents();

    printf("=================================================================\n");
    printf("   AI-ASSISTED STUDENT RECORD AND RESULT MANAGEMENT SYSTEM\n");
    printf("             UPES Dehradun - B.Tech CSE (PRC1001)\n");
    printf("=================================================================\n");
    printf("System initialized with %d student records.\n", student_count);

    do {
        printf("\n------------------------- MAIN MENU -------------------------\n");
        printf("1. Add Student Details\n");
        printf("2. Search and Display a Student Record\n");
        printf("3. Calculate CGPA of Each Student\n");
        printf("4. Calculate Average CGPA of Students by Year\n");
        printf("5. Display Records of All Students\n");
        printf("6. Delete an Individual Student Record\n");
        printf("7. Display All Records in Increasing Order of SAP ID\n");
        printf("8. Display All Records in Increasing Order of Name\n");
        printf("9. AI-Assisted Academic Advisor (Pending implementation)\n");
        printf("0. Exit\n");
        printf("-------------------------------------------------------------\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                searchStudent();
                break;
            case 3:
                calculateAllCGPA();
                break;
            case 4:
                averageCGPAByYear();
                break;
            case 5:
                displayAllStudents();
                break;
            case 6:
                deleteStudent();
                break;
            case 7:
                displaySortedBySapId();
                break;
            case 8:
                displaySortedByName();
                break;
            case 0:
                printf("\nExiting application. Goodbye!\n");
                break;
            default:
                printf("\nFeature under development or invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}
