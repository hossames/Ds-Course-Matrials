#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H
#include <iostream>
using namespace std;

template<class T> 
class SinglyLinkedList
{
	struct Node {
		T val;
		Node* next;
		Node(T val);
		Node();
	}*head, *tail;
	int length{ 0 };
public :
	SinglyLinkedList();
	void insertAt(int idx,T val);
	void deleteAt(int idx);
	void append(T val);
	T at(int idx);
	int Length();
	~SinglyLinkedList();
};

#include "SinglyLinkedList.cpp"
#endif

