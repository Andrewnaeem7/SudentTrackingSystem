#include "Student.h"
#include <fstream>

class Node {
public:
	Student student;
	Node* next;
	int getID() {
		return student.getID();
	}
};

class LinkedList {
private:
	Node* head;
	int count;
public:
	//Constructors
	LinkedList();

	//Methods
	void push_front(Student student);
	void push_back(Student student);
	void pop_front();
	void pop_back();
	void pop_at(int id);
	void displayAll();
	Student search(int id);
	int getCount();
	void save();
	//Destructor
	~LinkedList();

	//Utilities
	bool isEmpty();
	Node* tail();
	void emptyMsg();
	void clear();
};