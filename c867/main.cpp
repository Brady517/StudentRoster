#include "roster.h"
#include "student.h"
int main()
{
	cout << "-------------------------------------------------" << endl;
	cout << "Scripting and Programming - Applications - C867" << endl;
	cout << "C++" << endl;
	cout << "ID:010771698" << endl;
	cout << "Brady Osburn" << endl;
	cout << "-------------------------------------------------" << endl;

	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Brady,Osburn,bosbur1@wgu.edu,21,31,25,40,SOFTWARE"
	};
	const int numStudents = 5;

	Roster roster;

	for (int i = 0; i < numStudents; ++i) {
		roster.parse(studentData[i]);
	}


	cout << "Displaying all students:" << endl;
	roster.printAll();

	for (int i = 0; i < 3; i++)
	{
		cout << "Displaying by degree program:" << degreeProgramStrings[i] << endl;
		roster.printByDegreeProgram((DegreeProgram)i);
	}

	cout << "Displaying students with invalid emails:" << endl;
	roster.printInvalidEmails();

	cout << "Displaying average days to complete:" << endl;
	for (int i = 0; i < numStudents; i++) roster.printAverageDaysInCourse(roster.getStudents()[i]->getID());

	cout << "Removing A3" << endl;
	roster.remove("A3");


	cout << "Removing A3" << endl;
	roster.remove("A3");

	cout << "Finished. Destructors will be called automatically upon exit." << endl;
	return 0;



}