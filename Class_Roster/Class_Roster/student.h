#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;

class Student //this class represents a student
{

public: 
	const static int daysArraySize = 3;

private:  
	string studentID;
	string firstName;
	string lastName;
	int age;
	string email;
	int daysToCompletion[daysArraySize];
	DegreeProgram degreeprogram;
	
public: 

	//Constructor
	Student();
	Student(string studentID, string firstName, string lastName, int age, string email, int daysToCompletion[], DegreeProgram degreeprogram);
	~Student();



	//Getters for each instance field
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDaysToCompletion();
	DegreeProgram getDegreeProgram();

	//the setters
	void setStudentID(string ID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setAge(int age);
	void setEmail(string email);
	void setDaysToCompletion(int daysToCompletion[]);
	void setDegreeType(DegreeProgram degreeprogram);
	

	static void printHeader();

	void print();




};