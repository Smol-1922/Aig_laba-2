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
	void clear(); // очищение ассоциативного массива
	void preorder(Node* node); 
	List<std::string>* get_keys(); // возвращает список ключей
	List<char>* get_values();  // возвращает список букв
	List<int>* get_count();// возвращает список значений
	void create(queue* priority_queue);// возвращает список букв
	void Huffman(List_Hu* Huffman_table);// возвращает список букв
	void coding(Node* node,std::string& key);// возвращает список букв
};
#endif