#include"List.h"
#include"functionList.h"
#include"NodeBRTree.h"
#include"stack.h"
#include"functionStack.h"
#include <stdexcept>
#include<iostream>
RBTree::RBTree()
{
	Root = NULL;
}

RBTree::~RBTree()
{
	clear();
	Root = nullptr;
}
void RBTree::preorder(Node * node) {
	if (node == nullptr) return;
	preorder(node->Lnext);
	preorder(node->Rnext);
	delete node;
}

void RBTree ::clear() {
	preorder(Root);
	Root = nullptr;
}
List<std::string>* RBTree::get_keys()
{
	if (Root == NULL) {
		throw("There is no element");
	}
	stack  stackKey;
	List<std::string>* listKey = new List<std::string>;
	stackKey.push(Root);
	bool flag = true;
	Node* temp = stackKey.head->date;
	while (!stackKey.isEmpty()) {
		listKey->push_back(temp->key);
		if (temp->Rnext != NULL) {
			if (flag) {
				stackKey.pop_front();
				flag = false;
			}
			stackKey.push(temp->Rnext);
		}
		if (temp->Lnext != NULL) {
			temp = temp->Lnext;
		}
		else
		{

			if (flag) {
				stackKey.pop_front();
			}
			if (!stackKey.isEmpty()) {
				temp = stackKey.head->date;
			}
			flag = true;
		}
	}
	return listKey;
}
List<char>* RBTree ::get_values()
{
	if (Root == NULL) {
		throw("There is no element");
	}
	stack  stackValue;
	List<char>* listValue = new List<char>;
	stackValue.push(Root);
	bool flag = true;
	Node * temp = stackValue.head->date;
	while (!stackValue.isEmpty()) {
		listValue->push_back(temp->word);
		if (temp->Rnext != NULL) {
			if (flag) {
				stackValue.pop_front();
				flag = false;
			}
			stackValue.push(temp->Rnext);
		}
		if (temp->Lnext != NULL) {
			temp = temp->Lnext;
		}
		else
		{

			if (flag) {
				stackValue.pop_front();
			}
			if (!stackValue.isEmpty()) {
				temp = stackValue.head->date;
			}
			flag = true;
		}
	}
	return listValue;
}
List<int>* RBTree::get_count()
{
	if (Root == NULL) {
		throw("There is no element");
	}
	stack  stackValue;
	List<int>* listValue = new List<int>;
	stackValue.push(Root);
	bool flag = true;
	Node* temp = stackValue.head->date;
	while (!stackValue.isEmpty()) {
		listValue->push_back(temp->count);
		if (temp->Rnext != NULL) {
			if (flag) {
				stackValue.pop_front();
				flag = false;
			}
			stackValue.push(temp->Rnext);
		}
		if (temp->Lnext != NULL) {
			temp = temp->Lnext;
		}
		else
		{

			if (flag) {
				stackValue.pop_front();
			}
			if (!stackValue.isEmpty()) {
				temp = stackValue.head->date;
			}
			flag = true;
		}
	}
	return listValue;
}
void RBTree::create(queue* priority_queue) {
	while (priority_queue->get_size() > 1)
	{
		priority_queue->tree_construction();
		insertSort(priority_queue);
	}
	Root = priority_queue->head->date;
}
void RBTree::coding(Node* node,std::string& key) {
	if (node == nullptr) return;
	key += "0";
	coding(node->Lnext,key);
	node->key = key;
	key.erase(key.size() - 1);
	key += "1";
	coding(node->Rnext,key);
	key.erase(key.size() - 1);
	node->key = key;
}
void RBTree::Huffman(List_Hu * Huffman_table) {
	List<std::string>* List_keys=get_keys();
	List<char>* List_word=get_values();
	List<int>* List_count = get_count();
	for (unsigned int i = 0; i < List_keys->get_size(); i++) {
		if(List_word->at(i)!='\0')
		Huffman_table->push_back(List_keys->at(i),List_word->at(i),List_count->at(i));
	}
}