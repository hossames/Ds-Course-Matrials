#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H
#define CIRCULAR_DOUBLY_LINKED_LIST_H
#include <iostream>
using namespace std;

template<class T>
class CircularDoublyLinkedList
{
	struct Node {
		T val;
		Node* next;
		Node* prev;
		Node(T val);
		Node();
	}*head, * tail;
	int length{ 0 };
public:
	CircularDoublyLinkedList();
	void insertAt(int idx, T val);
	void deleteAt(int idx);
	void append(T val);
	T at(int idx);
	int Length();
	~CircularDoublyLinkedList();
};

#include "CircularDoublyLinkedList.cpp"
#endif

