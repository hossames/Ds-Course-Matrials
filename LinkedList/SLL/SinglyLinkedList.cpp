#ifndef SINGLY_LINKED_LIST_CPP
#define SINGLY_LINKED_LIST_CPP

#include "SinglyLinkedlist.h"
template<class T>
SinglyLinkedList<T>::Node::Node(T val)
{
	this->val = val;
	next = nullptr;
}

template<class T>
SinglyLinkedList<T>::Node::Node()
{
	next = nullptr;
	val = T();
}

template<class T>
SinglyLinkedList<T>::SinglyLinkedList()
{
	head = tail = nullptr;
}

template<class T>
void SinglyLinkedList<T>::insertAt(int idx,T val)
{
	if (idx<0 || idx>length)
		return void(cout << "out of range" << endl);
	Node* newNode =new Node(val);
	length++;
	if (idx == 0) {
		newNode->next = head;
		head = newNode;
		if (length == 1)
			tail = newNode;
		return;
	}
	if (idx == length-1) {
		tail->next = newNode;
		tail = newNode;
		return;
	}
	Node* temp = head;
	int i = 0;
	while (i < idx - 1) {
		i++;
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
}

template<class T>
void SinglyLinkedList<T>::deleteAt(int idx)
{
	if (idx<0 || idx>=length)
	{
		cout << "out of range" << endl;
		return;
	}
	length--;
	Node* temp = head;
	if (idx == 0) {
		head = head->next;
		delete temp;
		return;
	}
	int i = 0;
	while (i < idx - 1) {
		i++;
		temp = temp->next;
	}
	Node* del = temp->next;
	temp->next = del->next;
	if (idx == length)
		tail = temp;
	delete del;
}

template<class T>
void SinglyLinkedList<T>::append(T val)
{
	Node* newNode = new Node(val);
	length++;
	if (length == 1)
	{
		tail = head = newNode;
		return;
	}
	tail->next = newNode;
	tail = newNode;
}

template<class T>
T SinglyLinkedList<T>::at(int idx)
{
	if (idx<0 || idx>=length)
	{
		cout << "out of range" << endl;
		return T();
	}
	Node* temp = head;
	int i = 0;
	while (i < idx) {
		i++;
		temp = temp->next;
	}
	return temp->val;
}

template<class T>
int SinglyLinkedList<T>::Length()
{
	return length;
}

template<class T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
	Node* tmp;
	while (length--) {
		tmp = head->next;
		delete head;
		head = tmp;
	}
}
#endif