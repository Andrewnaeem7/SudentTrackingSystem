#include "StudentManger.h"

//methods

void StudentManger::addStudentFront(Student std) {
	student.push_front(std);
}

void StudentManger::addStudentBack(Student std) {
	student.push_back(std);
}

void StudentManger::deleteStudentFront() {
	student.pop_front();
}

void StudentManger::deleteStudentBack() {
	student.pop_back();
}

void StudentManger::deleteStudentWithId(int id) {
	student.pop_at(id);
}

Student StudentManger::getStudent(int id) {
	return student.search(id);
}

void StudentManger::displayAllStudent() {
	student.displayAll();
}

int StudentManger::numberOfStudentds()
{
	return student.getCount();
}

void StudentManger::saveAllStudents()
{
	student.save();
}
