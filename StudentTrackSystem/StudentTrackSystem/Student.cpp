#include "Student.h"
#include <fstream>

Student::Student()
{
	id = 0;
	name = "";
}

Student::Student(int id, string name, vector<float> grades)
{
	this->id = id;
	this->name = name;
	this->grades = grades;
}

void Student::setID(int id)
{
	this->id = id;
}

void Student::setName(string name)
{
	this->name = name;
}

void Student::setGrades(vector<float> grades)
{
	this->grades = grades;
}

int Student::getID() 
{ 
	return id;
}

string Student::getName()
{
	return name;
}

vector<float> Student::getGrades()
{
	return grades;
}

float Student::totalGrades()
{
	float sum = 0;
	for (int i = 0; i < grades.size(); i++) {
		sum += grades.at(i);
	}

	return sum;
}

string Student::courseStatus(int index)
{
	if (index < 0 || index >= grades.size())
		cout << "Out of bounderies!\n";
	else
		return (grades[index] < 50 ? "Failed" : "Passed");
}

void Student::display()
{
	float total = totalGrades();
	cout << "Student name: " << getName() << "\n";
	cout << "Student ID: " << getID() << "\n\n";
	for (int i = 0; i < grades.size(); i++) {
		cout << "Subject " << i + 1 << ": " << grades.at(i) << "\t=> " << courseStatus(i) << "\n";
	}
	cout << "Total: " << total << " => " << (total / (grades.size() * 100.f)) * 100 << "%";
}

void Student::saveStudentInfo()
{
	ofstream StudentsInfo;
	StudentsInfo.open("studentsInfo.txt", ios::app);

	float total = totalGrades();
	StudentsInfo << "Student ID: " << getID() << "\n\n";
	StudentsInfo << "Student name: " << getName() << "\n";
	for (int i = 0; i < grades.size(); i++) {
		StudentsInfo << "Subject " << i + 1 << ": " << grades.at(i) << "\t=> " << courseStatus(i) << "\n";
	}
	StudentsInfo << "Total: " << total << " => " << (total / (grades.size() * 100.f)) * 100 << "%";
	StudentsInfo << "\n============================\n\n";

}
