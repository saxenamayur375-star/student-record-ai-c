/*
 * Project Title : AI-Assisted Student Record and Result Management System
 * Course Name   : Programming in C (PRC1001)
 * Program       : B.Tech CSE (Semester I)
 * Student Name  : Mayur Saxena
 * SAP ID        : 590032873
 * Description   : Student record management - adding records, searching by SAP ID,
 *                 deleting by SAP ID, and formatted record display.
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
void loadSampleStudents();
void addStudent();
void searchStudent();
void deleteStudent();
void displayOneStudent(struct Student s);
void displayAllStudents();

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
    students[0].cgpa = 9.15f;

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
    students[1].cgpa = 7.85f;

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
    students[2].cgpa = 6.25f;

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
    students[3].cgpa = 5.10f;

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
    students[4].cgpa = 8.78f;

    student_count = 5;
}

/* Function to add a new student record */
void addStudent() {
    struct Student s;
    int i;
    float sum = 0.0f;
    int valid_sems = 0;

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
        if (s.sgpa[i] > 0.0f) {
            sum += s.sgpa[i];
            valid_sems++;
        }
    }

    s.cgpa = (valid_sems > 0) ? (sum / valid_sems) : 0.0f;

    students[student_count] = s;
    student_count++;

    printf("\n[Success] Student '%s' (SAP ID: %ld) added successfully!\n", s.name, s.sap_id);
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
        printf("3. Calculate CGPA (Pending implementation)\n");
        printf("4. Average CGPA by Year (Pending implementation)\n");
        printf("5. Display Records of All Students\n");
        printf("6. Delete an Individual Student Record\n");
        printf("7. Sort Records by SAP ID (Pending implementation)\n");
        printf("8. Sort Records by Name (Pending implementation)\n");
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
            case 5:
                displayAllStudents();
                break;
            case 6:
                deleteStudent();
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
