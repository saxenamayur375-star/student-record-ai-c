/*
 * Project Title : AI-Assisted Student Record and Result Management System
 * Course Name   : Programming in C (PRC1001)
 * Program       : B.Tech CSE (Semester I)
 * Student Name  : Mayur Saxena
 * SAP ID        : 590032873
 * Description   : Initial C program skeleton defining the Student structure,
 *                 global storage, and console menu interface.
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

/* Display basic info of all loaded students */
void displayAllStudents() {
    int i;
    printf("\n================ ALL STUDENT RECORDS (Total: %d) ================\n", student_count);
    for (i = 0; i < student_count; i++) {
        printf("SAP ID: %ld | Roll No: %s | Name: %-15s | Year: %d | Sem: %d | CGPA: %.2f\n",
               students[i].sap_id, students[i].roll_no, students[i].name,
               students[i].year, students[i].semester, students[i].cgpa);
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
        printf("1. Add Student Details (Pending implementation)\n");
        printf("2. Search Student Record (Pending implementation)\n");
        printf("3. Calculate CGPA (Pending implementation)\n");
        printf("4. Average CGPA by Year (Pending implementation)\n");
        printf("5. Display Records of All Students\n");
        printf("6. Delete Student Record (Pending implementation)\n");
        printf("7. Sort Records by SAP ID (Pending implementation)\n");
        printf("8. Sort Records by Name (Pending implementation)\n");
        printf("9. AI-Assisted Academic Advisor (Pending implementation)\n");
        printf("0. Exit\n");
        printf("-------------------------------------------------------------\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 5:
                displayAllStudents();
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
