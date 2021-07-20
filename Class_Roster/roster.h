#pragma once
#include <string>
#include "student.h";

class Roster : public Student
{
private:
	int lastIndex = -1;
	const static int numStudents = 5;


public:

	Student* classRosterArray[numStudents];

	void parse(string row);
	void add(
		string studentID,
		string firstName,
		string lastName,
		int age,
		string email,
		int daysToComplete1,
		int daysToComplete2,
		int daysToComplete3,
		DegreeProgram degreeprogram);

	//Roster();

	//Roster(string studentID, string firstName, string lastName, string age, string email, int daysToComplete[], DegreeType dType);

	void printAll();
	void printByDegreeType(DegreeProgram dtype);
	void printInvalidEmails();
	void printAverageDaysInCourse(string studentID); 
	void remove(string studentID);
	void printByDegreeProgram(DegreeProgram dtype);

	DegreeProgram getDegreeProgram();
	void print();

	~Roster();
};