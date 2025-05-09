#include "student.h"
Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < numDaysComplete; i++) this->days[i] = 0;
	this->degreeProgram = DegreeProgram::UNDECIDED;

}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int days[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < numDaysComplete; i++) this->days[i] = days[i];
	this->degreeProgram = degreeProgram;

}

Student::~Student() {}
//getters
string Student::getID() { return this->studentID; }
string Student::getFirst() { return this->firstName; }
string Student::getLast() { return this->lastName; }
string Student::getEmail() { return this->email; }
int Student::getAge() { return this->age; }
const int* Student::getDays() { return this->days; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

//setters
void Student::setID(string ID) { this->studentID = ID; }
void Student::setFirst(string firstName) { this->firstName = firstName; }
void Student::setLast(string lastName) { this->lastName = lastName; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setDays(const int days[])
{
	for (int i = 0; i < numDaysComplete; i++) this->days[i] = days[i];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

void Student::printHeader()
{
	cout << "ID\t";
	cout << "FirstName\t";
	cout << "LastName\t";
	cout << "Email\t";
	cout << "Age\t";
	cout << "Days1\t";
	cout << "Days2\t";
	cout << "Days3\t";
	cout << "Program\t";
	cout << endl;
}

void Student::print()
{
	cout << this->studentID << '\t';
	cout << this->firstName << '\t';
	cout << this->lastName << '\t';
	cout << this->email << '\t';
	cout << this->age << '\t';
	cout << this->days[0] << '\t';
	cout << this->days[1] << '\t';
	cout << this->days[2] << '\t';
	cout << degreeProgramStrings[(int)this->degreeProgram];
	cout << endl;
}