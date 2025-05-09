#include "roster.h"
#include "student.h"
using namespace std;

Student** Roster::getStudents()
{
	return students;
}

void Roster::parse(string studentData)
{
	vector<string> result;
	size_t start;
	size_t end = 0;
	while ((start = studentData.find_first_not_of(',', end)) != string::npos)
	{
		end = studentData.find(',', start);
		result.push_back(studentData.substr(start, end - start));
	}
	DegreeProgram dp = DegreeProgram::UNDECIDED;
	switch (result.at(8).back())
	{
	case 'Y': dp = DegreeProgram::SECURITY; break;
	case 'K': dp = DegreeProgram::NETWORK; break;
	case 'E': dp = DegreeProgram::SOFTWARE; break;
	}
	add(result.at(0), result.at(1), result.at(2), result.at(3), stoi(result.at(4)), stoi(result.at(5)), stoi(result.at(6)), stoi(result.at(7)), dp);
}
void Roster::add(string studentID, string firstName, string lastName, string email, int age, int days1, int days2, int days3, DegreeProgram dp)
{
	int daysInCourse[3] = { days1,days2,days3 };
	students[++lastIndex] = new Student(studentID, firstName, lastName, email, age, daysInCourse, dp);
	cout << "Student added to class roster at row" << lastIndex + 1 << endl;
}

void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) Roster::students[i]->print();
}

void Roster::printByDegreeProgram(DegreeProgram dp)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
		if (Roster::students[i]->getDegreeProgram() == dp) students[i]->print();
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		string email = Roster::getStudents()[i]->getEmail();
		if (email.find(' ') != string::npos || email.find('.') == string::npos || email.find('@') == string::npos)
			cout << email << " Is invalid!" << endl;
	}
}

void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (students[i]->getID() == studentID)
		{
			cout << studentID << ":";
			cout << (students[i]->getDays()[0] +
				students[i]->getDays()[1] +
				students[i]->getDays()[2]) / 3.0 << endl;
		}
	}
}

void Roster::remove(string studentID)
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (students[i]->getID() == studentID)
		{
			success = true;
			Student* temp = students[i];
			students[i] = students[numStudents - 1];
			students[numStudents - 1] = temp;
			Roster::lastIndex--;
		}
	}
	if (success)
	{
		cout << "Student " << studentID << " removed." << endl;
		printAll();

	}
	else cout << "Student " << studentID << " not found." << endl;
}

Roster::~Roster()
{
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Destructor called for " << students[i]->getID() << endl;
		delete students[i];
		students[i] = nullptr;
	}
}