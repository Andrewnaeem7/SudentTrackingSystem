#include "LinkedList.h"
#include <fstream>

//Constructors

LinkedList::LinkedList() {
	head = nullptr;
	count = 0;
}

//Methods

void LinkedList::push_front(Student student) {
	Node* newNode = new Node;
	newNode->student = student;
	newNode->next = head;
	head = newNode;
	count++;
}

void LinkedList::push_back(Student student) {
	if (isEmpty())
		push_front(student);
	else {
		Node* newNode = new Node;
		newNode->student = student;
		newNode->next = nullptr;

		Node* temp = tail();
		temp->next = newNode;
		count++;
	}

}

void LinkedList::pop_front() {
	if (isEmpty())
		emptyMsg();
	else {
		Node* temp = head;
		head = head->next;
		delete temp;
		count--;
	}
}

void LinkedList::pop_back() {
	if (isEmpty())
		emptyMsg();
	else if (head->next == nullptr)
		pop_front();
	else {
		Node* temp = head;
		while (temp->next->next != nullptr)
			temp = temp->next;

		delete temp->next;
		temp->next = nullptr;
		count--;
	}
}

void LinkedList::pop_at(int id) {
	if (isEmpty())
		emptyMsg();
	else {
		bool found = false;
		Node* temp = head;
		Node* temp1 = nullptr;

		if (temp->student.getID() == id) {
			pop_front();
		}else{
			while (temp->next != nullptr && temp->next->student.getID() != id)
				temp = temp->next;

			if (temp->next != nullptr && temp->next->student.getID() == id) {
				temp1 = temp->next;
				temp->next = temp->next->next;
				delete temp1;
				found = true;
				count--;
			}

			if (!found)
				cout << "There is no student with the given ID!\n";
		}
	}
}

Student LinkedList::search(int id) {
	if (isEmpty())
		emptyMsg();
	else {
		Node* temp = head;
		while (temp->student.getID() != id && temp->next != nullptr)
			temp = temp->next;

		if (temp != nullptr && temp->student.getID() == id)
			return temp->student;
		else
			cout << "No such student with that ID!\n";
	}

}

int LinkedList::getCount()
{

	return count;
}

void LinkedList::save()
{
	if (isEmpty())
		emptyMsg();
	else {
		ofstream StudentsInfo;
		StudentsInfo.open("studentsInfo.txt");
		StudentsInfo.clear();
		StudentsInfo.close();
		Node* temp = head;
		while (temp != nullptr) {
			temp->student.saveStudentInfo();
			temp = temp->next;
		}
	}
}

void LinkedList::displayAll() {
	if (isEmpty())
		emptyMsg();
	else {
		Node* temp = head;
		while (temp != nullptr) {
			temp->student.display();
			cout << "\n==========================\n\n";
			temp = temp->next;
		}
	}
}

//Destructor

LinkedList::~LinkedList() {
	clear();
}

//Utilities

bool LinkedList::isEmpty() {
	return head == nullptr;
}

Node* LinkedList::tail() {
	Node* temp = head;
	while (temp->next != nullptr)
		temp = temp->next;

	return temp;
} 

void LinkedList::emptyMsg() {
	cout << "The list is empty!\n";
}

void LinkedList::clear() {
	Node* temp1 = head;
	Node* temp2 = nullptr;

	while (temp1 != nullptr) {
		temp2 = temp1;
		temp1 = temp1->next;
		delete temp2;
	}

	head = nullptr;
}
