#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Student {
    int id;
    char name[50];
    char fatherName[50];
    char address[100];
    int contactNo;
    float grade;
};

struct Student students[MAX];
int count = 0;
int filePass = 987123;

// Function declarations
void countAndAdd();
void addStudent();
void deleteStudent();
void displayStudents();
void searchStudents();
void updateStudents();

int main() {
    int pass;
    printf("Enter Password : ");
    scanf("%d", &pass);
    if(pass != filePass){
        printf("Wrong Password -> Access Denied");
    }
    int choice;
    countAndAdd();
    while (1) {
        printf("\n--------Student Management System--------");
        printf("\n1. Add student");
        printf("\n2. Delete student");
        printf("\n3. Display student");
        printf("\n4. Search student");
        printf("\n5. Update data");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: deleteStudent(); break;
            case 3: displayStudents(); break;
            case 4: searchStudents(); break;
            case 5: updateStudents(); break;
            case 6: exit(0);
            default: printf("Invalid input\n");
        }
    }
    return 0;
}
//count the no of student
void countAndAdd() {
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) return;

    while (count < MAX && fscanf(fp, "%d,%49[^,],%49[^,],%99[^,],%d,%f\n",
        &students[count].id,
        students[count].name,
        students[count].fatherName,
        students[count].address,
        &students[count].contactNo,
        &students[count].grade) == 6) {
        count++;
    }

    fclose(fp);
}
//add student details
void addStudent() {
    struct Student s;
    FILE *fp = fopen("students.txt", "a");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter Student ID: ");
    scanf("%d", &s.id);
    getchar();
    printf("Enter Student Name: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';

    printf("Enter Father's Name: ");
    fgets(s.fatherName, sizeof(s.fatherName), stdin);
    s.fatherName[strcspn(s.fatherName, "\n")] = '\0';

    printf("Enter Address: ");
    fgets(s.address, sizeof(s.address), stdin);
    s.address[strcspn(s.address, "\n")] = '\0';

    printf("Enter Contact Number: ");
    scanf("%d", &s.contactNo);

    printf("Enter Grade: ");
    scanf("%f", &s.grade);

    students[count++] = s;
    fprintf(fp, "%d,%s,%s,%s,%d,%.2f\n",
            s.id, s.name, s.fatherName, s.address, s.contactNo, s.grade);
    fclose(fp);

    printf("Student added successfully!\n");
}


void deleteStudent() {// for delete the students data
    int delete, found = -1;
    if (count == 0 || count >= MAX ) {
        printf("No records found.\n");
        return;
    }

   printf("Enter Student ID to delete: ");
    scanf("%d", &delete);

    for (int i = 0; i < count; i++) {
        if (students[i].id == delete) {
            found = i;
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            break;
        }
    }

    if (found == -1) {
        printf("Student not found.\n");
        return;
    }

    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error writing file.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d,%s,%s,%s,%d,%.2f\n",
                students[i].id,
                students[i].name,
                students[i].fatherName,
                students[i].address,
                students[i].contactNo,
                students[i].grade);
    }
    fclose(fp);
    printf("Student deleted successfully.\n");
}


//display the studens details
void displayStudents() {
    if(count == 0){
        printf("No records found");
    }
    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Father's Name: %s\n", students[i].fatherName);
        printf("Address: %s\n", students[i].address);
        printf("Contact No: %d\n", students[i].contactNo);
        printf("Grade: %.2f\n", students[i].grade);
        printf("------------------------\n");
    }
}


//for search the student with id
    void searchStudents() {
    int searchId, found = 0;

    if (count == 0) {
        printf("No records found.\n");
        return;
    }

   printf("Enter Student ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < count; i++) {
        if (students[i].id == searchId) {
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Father's Name: %s\n", students[i].fatherName);
            printf("Address: %s\n", students[i].address);
            printf("Contact No: %d\n", students[i].contactNo);
            printf("Grade: %.2f\n", students[i].grade);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}


//update the students details
void updateStudents() {
    int id, found = -1;
    printf("Enter Student ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            found = i;
            printf("Enter new name: ");
            scanf(" %[^\n]", students[i].name);
            printf("Enter new father's name: ");
            scanf(" %[^\n]", students[i].fatherName);
            printf("Enter new address: ");
            scanf(" %[^\n]", students[i].address);
            printf("Enter new contact number: ");
            scanf("%d", &students[i].contactNo);
            printf("Enter new grade: ");
            scanf("%f", &students[i].grade);
            break;
        }
    }

    if (found == -1) {
        printf("Student not found.\n");
        return;
    }

    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Error writing file.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d,%s,%s,%s,%d,%.2f\n",
                students[i].id,
                students[i].name,
                students[i].fatherName,
                students[i].address,
                students[i].contactNo,
                students[i].grade);
    }
    fclose(fp);

    printf("Student updated successfully.\n");
}
