#pragma once
#include <vector>
#include "student.h"

class Roster
{
private:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* students[numStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr };

public:


	Student** getStudents();
	void parse(string row);

	void add(string studentID, string firstName, string lastName, string email, int age, int days1, int days2, int days3, DegreeProgram dp);
	void printAll();
	void remove(string studentID);
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

	~Roster();
};

