**Student Management System**
This Student Management System is implemented in C++ using a linked list to store and manage student records. The project allows you to add, update, delete, search, display student data, check if a student has passed or failed, and determine the topper. The records are also stored in a file for persistent data storage.

**Features**
  - Add a student record (Roll No, Name, Gender, Marks, Courses, CGPA)
  - Display all student records from the file or from the list
  - Delete a student record (first student or by roll number)
  - Search a student by roll number
  - Update an existing student's information
  - Check if a student has passed or failed based on their marks
  - Find the topper with the highest marks
  - File handling for persistent storage of student records
  - Simple user authentication (default username: "1", password: "1")

**Project Structure**
**node:** A struct to hold student information (roll number, name, gender, marks, courses, CGPA) and a pointer to the next node.
**LinkedList:** A class that implements all the functionality like insertion, deletion, searching, updating, and file handling.

**How to Run**
- Clone or download this repository.
- Compile the C++ file using any C++ compiler, for example:
    g++ student_management.cpp -o student_management
  
- Run the compiled file:
    ./student_management
  
- Enter the default username and password when prompted:
    Username: 1
    Password: 1

**Menu Options**
Press 1: Insert a student record.
Press 2: Display all records from the file.
Press 3: Delete a student record.
Press 4: Search for a student by roll number.
Press 5: Update a student's information.
Press 6: Check if a student passed or failed.
Press 7: Get the topper's information.
Press 8: Exit the program.
Press 9: Display all records from the linked list.

**Author**
This project was developed by:

Syed Qasim Ibrar Shah

Feel free to contribute or fork this project to improve its features!
