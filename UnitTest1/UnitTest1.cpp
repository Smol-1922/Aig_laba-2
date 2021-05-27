#include "pch.h"
#include "CppUnitTest.h"
#include  "E:\Rep\Aig_laba№2\A\function.h"
#include  "E:\Rep\Aig_laba№2\A\List.h"
#include  "E:\Rep\Aig_laba№2\A\List_Huffman.h"
#include  "E:\Rep\Aig_laba№2\A\functionList_H.h"
#include  "E:\Rep\Aig_laba№2\A\RBTree.h"
#include  "E:\Rep\Aig_laba№2\A\functionBRTree.h"
#include<string>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::string sentence = "Ура оно работает!!!";
			queue* que_string = new queue;
			queue* que= new queue;
			count(sentence, que);
			que_string->push('У', 1);
			que_string->push('р', 2);
			que_string->push('а', 3);
			que_string->push('о', 3);
			que_string->push('н', 1);
			que_string->push('б', 1);
			que_string->push('т', 2);
			que_string->push('е', 1);
			que_string->push('!', 3);
			que_string->push(' ', 2);
			for (int i = 0; i < que_string->get_size(); i++) {
				for (int j = 0; j < que->get_size(); j++) {
					if(que->at_w(j)==que_string->at_w(i))
					Assert::IsTrue(que->at_c(j)== que_string->at_c(i));
				}
			}
		}
		TEST_METHOD(TestMethod2)
		{
			std::string sentence = "Проверка";
			std::string encoding = "0000100111011101100101";
			std::string k = "";
			queue* que = new queue;
			RBTree* tree_sentence = new RBTree;
			List_Hu* list = new List_Hu;
			count(sentence, que);
			tree_sentence->create(que);
			tree_sentence->coding(tree_sentence->Root, k);
			tree_sentence->Huffman(list);
			std::string string_enc = string_encoding(sentence, list);
			std::string string_dec = string_decoding(string_enc, tree_sentence);
			Assert::IsTrue(string_enc == encoding);
			Assert::IsTrue(string_dec == sentence);

		}
		TEST_METHOD(TestMethod3)
		{
			unsigned int arr[10] = {1,1,1,1,2,2,2,3,3,3};
			queue* que_string = new queue;
			que_string->push('У', 1);
			que_string->push('р', 2);
			que_string->push('а', 3);
			que_string->push('о', 3);
			que_string->push('н', 1);
			que_string->push('б', 1);
			que_string->push('т', 2);
			que_string->push('е', 1);
			que_string->push('!', 3);
			que_string->push(' ', 2);
			insertSort(que_string);
			for (int i = 0; i < que_string->get_size(); i++) {
					Assert::IsTrue(arr[i] == que_string->at_c(i));
			}
		}
		TEST_METHOD(TestMethod4)
		{
			queue* que = new queue;
			char test = 'f';
			que->push('g');
			que->push('f');
			que->push('d');
			Assert::IsTrue(que->at_w(1) == test);
			
		}
		TEST_METHOD(TestMethod6)
		{
			unsigned int test= 2;
			queue* que = new queue;
			que->push('g',2);
			que->push('f', 1);
			que->push('d', 4);
			Assert::IsTrue(que->at_c(0) == test);
		}
		TEST_METHOD(TestMethod7)
		{
			queue* que = new queue;
			que->push('g');
			que->add_at(0);
			Assert::IsTrue(que->at_c(0) == 2);
			que->add_at(0);
			Assert::IsTrue(que->at_c(0) == 3);
		}
	};
}