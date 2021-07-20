#include<iostream>
#include <string>
#include "roster.h";
//using namespace std;
//using std::endl;

int main() {

	cout << "course title: Scripting and Programming-Applications-C867"
		 << " C++ "
		 << " student ID: 001265089 "
		 << " Student Name: Daphne Orme "
		 << std::endl
	     << std::endl;
	const std::string studentData[] =

	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	  "A5,Daphne,Orme,dorme10@wgu.edu,20,12,13,14,SOFTWARE"
	};

	const int numStudents = 5;
	Roster roster;

	for (int i = 0; i < numStudents; i++)
	{
		roster.parse(studentData[i]);

	}

		cout << "Displaying all students" << std::endl;
		roster.printAll();
		cout << std::endl;

		cout << "Displaying students with invalid emails " << std::endl;
		roster.printInvalidEmails();
		cout << std::endl;

		cout << "Displaying average days in course " << std::endl;
		for (Student* ele : roster.classRosterArray)
		{
			roster.printAverageDaysInCourse(ele->getStudentID());
		}

		cout << "Displaying by degree program: SOFTWARE" << std::endl;
		roster.printByDegreeProgram(SOFTWARE);


		cout << "Removing student with ID A3" << std::endl;
		roster.remove("A3");
		cout << std::endl;

		cout << "printing students" << std::endl;
		roster.printAll();
		cout << std::endl;

		cout << "Removing student with ID A3" << std::endl;
		roster.remove("A3");
		cout << std::endl;

		system("pause");
		return 0;


	

}