#include <iostream>
#include<string>
#include "roster.h";
using std::cout;

void Roster::parse( const string studentdata)
{
	 DegreeProgram degreeprogram = UNDECIDED; 
	if (studentdata.back() == 'K')
	{
		degreeprogram = NETWORK;
	}
	else if (studentdata.back() == 'E')
	{
		degreeprogram = SOFTWARE;
	}
	else if (studentdata.back() == 'Y')
	{
		degreeprogram = SECURITY;
	}

	int rhs = studentdata.find(",");
	string sID = studentdata.substr(0, rhs); //student ID

	int lhs = rhs + 1;
	rhs = studentdata.find("," , lhs);
	string fN = studentdata.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string lN = studentdata.substr(lhs, rhs - lhs);


	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string em = studentdata.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int age = stoi(studentdata.substr(lhs, rhs - lhs));


	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int g1 = stoi(studentdata.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int g2 = stoi(studentdata.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int g3 = stoi(studentdata.substr(lhs, rhs - lhs));


	add(sID, fN, lN, age, em, g1, g2, g3, degreeprogram);


}

void Roster::add(string studentID, string firstName, string lastName, int age, string email, int daysToComplete1, int daysToComplete2, int daysToComplete3, DegreeProgram degreeprogram)
{
	int daysToComplete[3] = { daysToComplete1, daysToComplete2, daysToComplete3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, age, email, daysToComplete, degreeprogram);


}

void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		cout << classRosterArray[i]->getStudentID(); cout << '\t';
		cout << classRosterArray[i]->getFirstName(); cout << '\t';
		cout << classRosterArray[i]->getLastName(); cout << '\t';
		cout << classRosterArray[i]->getAge(); cout << '\t';
		cout << classRosterArray[i]->getEmail(); cout << '\t';
		cout << classRosterArray[i]->getDaysToCompletion()[0]; cout << '\t';
		cout << classRosterArray[i]->getDaysToCompletion()[1]; cout << '\t';
		cout << classRosterArray[i]->getDaysToCompletion()[2]; cout << '\t';
		cout << degreeProgramStrings[classRosterArray[i]-> getDegreeProgram()]  << std::endl;
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeprogram)
{
	Student::printHeader();
	for (int i = 0; i < Roster::lastIndex; i++)
	{
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeprogram)
		{
			classRosterArray[i]->print();
		}

	}

	cout << std::endl;
}

//A valid email should include an at sign ('@') 
//and period ('.') and should not include a space (' ').
void Roster::printInvalidEmails()
{
	bool flag = false;

	for (int i = 0; i < Roster::lastIndex; i++)
	{
		string email = (classRosterArray[i]->getEmail());
		if (email.find('@') == string::npos && email.find('.') == string::npos  || email.find(' '))
		{
			flag = true;
			cout << email << " : " << classRosterArray[i]->getEmail() << std::endl;
		}
		else
		{
			cout << "NONE" << std::endl;

		}
	}
}

void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (Roster::classRosterArray[i]->getStudentID() == studentID )
		{
			cout << classRosterArray[i]->getStudentID() << " :";
			cout << (classRosterArray[i]->getDaysToCompletion()[0] +
				classRosterArray[i]->getDaysToCompletion()[1] +
				classRosterArray[i]->getDaysToCompletion()[2]) / 3 << std::endl;
		}
		cout << std::endl;
	}

}

void Roster::remove(string studentID)
{
	bool found = false;
	for (int i = 0; i < Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			found = true;
			if (i < numStudents - 1)
			{
				Student* temp = classRosterArray[i]; //A3
				classRosterArray[i] = classRosterArray[numStudents - 1]; //A3 = A5
				classRosterArray[numStudents - 1] = temp; //A5 = A3
				temp = classRosterArray[numStudents - 2]; //A4
				classRosterArray[numStudents - 2] = classRosterArray[i]; //A4 = A5
				classRosterArray[i] = temp;
				

			}

			Roster::lastIndex--;
		}

	}

	if (found) 
	{
		cout << studentID << " removed from roster." << std::endl << std::endl;
	}
	else
	{
		cout << studentID << " not found." << std::endl << std::endl;
	}
}

Roster::~Roster()
{
	cout << "DESTRUCTOR CALLED!" << std::endl << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Destroying book # " << i + 1 << std::endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;

	}

}






