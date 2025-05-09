# Student Roster Management System

This C++ program manages a roster of students. It allows you to perform various operations such as adding students, displaying student information, searching for students, and removing students.

## Project Description

The program utilizes the following classes and data structures:

* **Student Class:** Represents a single student with attributes like ID, first name, last name, email, age, days to complete courses, and degree program.
* **Roster Class:** Manages a collection of `Student` objects and provides methods to perform operations on the roster.
* **DegreeProgram Enum:** Defines the possible degree programs (SECURITY, NETWORK, SOFTWARE).

## Files Included

* `main.cpp`: The main program file that initializes data, creates a `Roster` object, and demonstrates the program's functionality.
* `student.h`: Header file for the `Student` class.
* `student.cpp`: Implementation file for the `Student` class.
* `roster.h`: Header file for the `Roster` class.
* `roster.cpp`: Implementation file for the `Roster` class.
* `degree.h`: Header file for the `DegreeProgram` enum.

## Features

* **Add Students:** Adds new students to the roster.
* **Display All Students:** Prints information for all students in the roster.
* **Display by Degree Program:** Prints students filtered by their degree program.
* **Display Invalid Emails:** Identifies and prints students with invalid email addresses.
* **Display Average Days in Course:** Calculates and prints the average number of days to complete courses for each student.
* **Remove Student:** Removes a student from the roster by student ID.
