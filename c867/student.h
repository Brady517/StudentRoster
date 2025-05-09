#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"

using std::cout;
using std::endl;
using std::left;
using std::setw;
using std::string;

class Student
{
public:
	const static int numDaysComplete = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int days[numDaysComplete];
	DegreeProgram degreeProgram;
public:
	Student();

	Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeProgram degreeProgram);
	~Student();

	//getters
	string getID();
	string getFirst();
	string getLast();
	string getEmail();
	int getAge();
	const int* getDays();
	DegreeProgram getDegreeProgram();

	//setters
	void setID(string studentID);
	void setFirst(string firstName);
	void setLast(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDegreeProgram(DegreeProgram dp);
	void setDays(const int days[]);

	static void printHeader();//display categories across top

	void print();// display student info





};