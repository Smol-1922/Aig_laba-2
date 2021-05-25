#ifndef stack_H
#define stack_H
#include"RBTree.h"
#include"NodeBRTree.h"
class stack
{
private:
	class stackNode {
	public:
		Node* date;
		stackNode* next;

		stackNode(Node* date = nullptr, stackNode* next = nullptr)
		{
			this->date = date;
			this->next = next;
		};
		~stackNode()
		{

		}

	};
public:
	stackNode* head;
	stackNode* tail;
	unsigned int size;
	stack();
	~stack();
	void clear();
	bool isEmpty();
	void push(Node* date);
	void pop_front();
	void pop_back();
	void reset_list();
};
#endif