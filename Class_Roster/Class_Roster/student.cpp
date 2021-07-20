#include<iostream>
#include<iomanip>
#include "student.h"

using std::cout;
using std::left;
using std::setw;

Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->age;
	this->email = "";

	for (int i = 0; i < daysArraySize; i++) this->daysToCompletion[i] = 0;
	this->degreeprogram = DegreeProgram::UNDECIDED;

}

Student::Student(string studentID, string firstName, string lastName, int age, string email, int daysToCompletion[], DegreeProgram degreeprogram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->age = age;
	this->email = email;
	for (int i = 0; i < daysArraySize; i++) { 
		this->daysToCompletion[i] = daysToCompletion[i];
	}
	this->degreeprogram = degreeprogram;
}

Student::~Student()
{

}

//Getters
string Student::getStudentID()
{
	return this->studentID;
}
string Student::getFirstName()
{
	return this->firstName;
}
string Student::getLastName()
{
	return this->lastName;
}
int Student::getAge()
{
	return this->age;
}
string Student::getEmail()
{
	return this->email;
}
int* Student::getDaysToCompletion() //you can return array as pointer
{
	return this->daysToCompletion;
}
DegreeProgram Student::getDegreeProgram()
{
	return this->degreeprogram;
}

//Setters
void Student::setStudentID(string ID)
{
	this->studentID = ID; 
}
void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}
void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setEmail(string email)
{
	this->email = email;
}
void Student::setDaysToCompletion(int daysToCompletion[])
{
	for (int i = 0; i < daysArraySize; i++) {
		this->daysToCompletion[i] = daysToCompletion[i];
	}
}
void Student::setDegreeType(DegreeProgram degreeprogram)
{
	this->degreeprogram = degreeprogram;
}

void Student::setAge(int age)
{
	this->age = age;
}

//header
void Student::printHeader()
{
	cout << "Output format: ID|FIRST NAME|LAST NAME|AGE|EMAIL|DAYS LEFT|DEGREE|\n";
}

//print method
void Student::print()
{
	cout << this->getStudentID() << '\t';
	cout << this->getFirstName() << "\t";
	cout << this->getAge() << "\t";
	cout << this->getEmail() << "\t";
	cout << this->getDaysToCompletion()[0] << "\t";
	cout << this->getDaysToCompletion()[1] << "\t";
	cout << this->getDaysToCompletion()[2] << "\t";
	cout << degreeProgramStrings[this->getDegreeProgram()] << '\n';
	

}

