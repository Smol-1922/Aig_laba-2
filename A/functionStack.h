#include"RBTree.h"
#include"stack.h"
#include"NodeBRTree.h"
 
stack::stack() {
	head = nullptr;
	tail = nullptr;
	size = 0;
}
 
stack::~stack() {
	clear();
}
 
void stack::clear() {
	while (size != 0)
	{
		pop_front();
	}
}
 
bool stack::isEmpty() {
	if (size != 0) {
		return 0;
	}
	return 1;
}
 
void stack::push(Node* date) {
	if (size == 0) {
		head = new stackNode(date);
		tail = head;
	}
	else {
		head = new stackNode(date, head);
	}
	size++;
}
 
void stack::pop_front() {
	if (size == 0) {
		return;
	}
	if (size == 1) {
		delete head;
		reset_list();
	}
	else {
		stackNode* current = head;
		head = head->next;
		delete current;
	}
	size--;

}
 
void stack::pop_back() {
	if (size == 0) return;
	if (size == 1) {
		delete head;
		reset_list();
	}
	else {
		stackNode* current = head;
		while (current->next != tail) {
			current = current->next;
		}
		current->next = nullptr;
		delete tail;
		tail = current;
	}
	size--;
}
 
void stack::reset_list()
{
	head = nullptr;
	tail = nullptr;
}

