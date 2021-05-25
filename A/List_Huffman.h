#ifndef List_Huffman_H
#define List_Huffman_H
class List_Hu
{
public:
	List_Hu();
	~List_Hu();
	void reset_list();
	void push_back(std::string key, char word,int count); // adding to the end of the list
	void push_front(std::string key, char word, int count); // adding to the top of the list
	void pop_back(); // deleting the last element
	void pop_front(); // deleting the first element
	unsigned int get_size(); // getting the list size
	void print_to_console(); // output list items to the console using a separator
	void clear(); // deleting all list items
	bool isEmpty(); // checking if the list is empty
	std::string at_k(unsigned int index);
	int at_c(unsigned int index);
	char at_v(unsigned int index);
private:
	class List_HNode {
	public:
		std::string key;
		char word;
		int count;
		List_HNode* next;

		List_HNode(std::string key, char word,int count, List_HNode* next = nullptr)
		{
			this->count = count;
			this->word = word;
			this->key = key;
			this->next = next;
		};
		~List_HNode()
		{

		}

	};
	List_HNode* tail;
	List_HNode* head;
	unsigned int size;
};
#endif
