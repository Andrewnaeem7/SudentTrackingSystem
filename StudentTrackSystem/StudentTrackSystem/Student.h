#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
	int id;
	string name;
	vector<float> grades;

public:
	//Constructors
	Student();
	Student(int id, string name, vector<float> grades);

	//Setters
	void setID(int id);
	void setName(string name);
	void setGrades(vector<float> grades);

	//Getters
	int getID();
	string getName();
	vector<float> getGrades();

	//Utilities
	float totalGrades();
	string courseStatus(int index);
	void display();
	void saveStudentInfo();
};