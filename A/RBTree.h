#ifndef RBTree_H
#define RBTree_H
#include"NodeBRTree.h"
#include"stack.h"
#include"List.h"
#include"List_Huffman.h"
#include"queue.h"
class RBTree
{
public:
	RBTree();
	~RBTree();
	Node* Root;
	void clear(); // �������� �������������� �������
	void preorder(Node* node); 
	List<std::string>* get_keys(); // ���������� ������ ������
	List<char>* get_values();  // ���������� ������ ����
	List<int>* get_count();// ���������� ������ ��������
	void create(queue* priority_queue);// ���������� ������ ����
	void Huffman(List_Hu* Huffman_table);// ���������� ������ ����
	void coding(Node* node,std::string& key);// ���������� ������ ����
};
#endif