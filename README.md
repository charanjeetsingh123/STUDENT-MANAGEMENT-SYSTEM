# STUDENT-MANAGEMENT-SYSTEM
📚 Student Management System (C Language)
A simple console-based Student Management System written in C that stores, updates, deletes, searches, and displays student information.
The system uses a text file (students.txt) for persistent data storage.

🚀 Features
Password-Protected Access
Only users with the correct password can use the system.

Add Student
Add a new student with details such as:

Student ID

Name

Father's Name

Address

Contact Number

Grade

Delete Student
Remove a student by their ID.

Display Students
Show all stored student records.

Search Student
Find a student by ID.

Update Student
Modify student details.

Persistent Storage
Data is stored in a students.txt file and is reloaded at program start.

🛠 How It Works
Password Authentication

The program asks for a password before access.

Default password: 987123


Menu Options
1. Add student
2. Delete student
3. Display students
4. Search student
5. Update student
6. Exit
File Handling

On startup, the program reads from students.txt to load existing data.



Each operation updates the file to ensure data is saved.
🖥 Sample Output
Enter Password : 987123

--------Student Management System--------
1. Add student
2. Delete student
3. Display student
4. Search student
5. Update data
6. Exit
Enter your choice: 1
Enter Student ID: 101
Enter Student Name: John Doe
Enter Father's Name: Michael Doe
Enter Address: 123 Street
Enter Contact Number: 9876543210
Enter Grade: 85.50
Student added successfully!


⚠ Notes
Ensure students.txt is in the same folder as the executable.

Maximum number of students is set to 100 (MAX constant in code).

Contact number is stored as an integer, so leading zeros will be removed.

All file writes overwrite the previous version when deleting or updating records.


