#include "LinkedList.h"

//Interface class
class StudentManger {
private:
	LinkedList student;
public:
	//methods
	void addStudentFront(Student std);
	void addStudentBack(Student std);
	void deleteStudentFront();
	void deleteStudentBack();
	void deleteStudentWithId(int id);
	Student getStudent(int id);
	void displayAllStudent();
	int numberOfStudentds();
	void saveAllStudents();
};