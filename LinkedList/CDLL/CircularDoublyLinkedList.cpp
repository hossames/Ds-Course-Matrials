#ifndef CIRCULAR_DOUBLY_LINKED_LIST_CPP
#define CIRCULAR_DOUBLY_LINKED_LIST_CPP

#include "CircularDoublyLinkedlist.h"
template<class T>
CircularDoublyLinkedList<T>::Node::Node(T val)
{
	this->val = val;
	next = prev = nullptr;
}

template<class T>
CircularDoublyLinkedList<T>::Node::Node()
{
	next = prev = nullptr;
	val = T();
}

template<class T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList()
{
	head = tail = nullptr;
}

template<class T>
void CircularDoublyLinkedList<T>::insertAt(int idx, T val)
{
	if (idx<0 || idx>length)
		return void(cout << "out of range" << endl);
	Node* newNode = new Node(val);
	length++;
	if (idx == 0) { // begin insertion
		if (head == nullptr) { // empty linked list
			head = tail = newNode;
			// circle connection
			head->next = head->prev = head;
			//
		}
		else { // add to begin  x -> head , x <- head , make x head
			head->prev = newNode;
			newNode->next = head;
			head = newNode;
			// circle connection
			head->prev = tail;
			tail->next = head;
			//
		}
		return;
	}
	if (idx == length - 1) { // end insertion
		length--; // restore length
		append(val); // calling append logic
		return;
	}
	// middle insertion
	Node* temp = head;
	for (int i = 0; i < idx - 1; i++)
		temp = temp->next;
	newNode->next = temp->next;
	newNode->next->prev = newNode;
	temp->next = newNode;
	newNode->prev = temp;
}

template<class T>
void CircularDoublyLinkedList<T>::deleteAt(int idx)
{
	if (idx < 0 || idx >= length)
	{
		cout << "out of range" << endl;
		return;
	}
	length--;
	Node* temp = head;
	if (idx == 0) { // begin deletion
		if (length == 0)
		{
			head = tail = nullptr;
		}
		else {
			head = head->next;
			// circle connection
			head->prev = tail;
			tail->next = head;
			//
		}
		delete temp;
		return;
	}

	if (idx == length) {// end deletion
		temp = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete temp;
		// circle connection
		head->prev = tail;
		tail->next = head;
		//
		return;
	}

	// middle deletion

	for (int i = 0; i < idx - 1; i++)
		temp = temp->next;

	Node* del = temp->next;
	temp->next = del->next;
	del->next->prev = temp;
	delete del;
}

template<class T>
void CircularDoublyLinkedList<T>::append(T val)
{
	Node* newNode = new Node(val);

	length++;
	if (head == nullptr) { // empty linked list
		tail = head = newNode;
		// circle connection
		head->prev = head->next = head;
		//
		return;
	}

	// normal insertion
	tail->next = newNode;
	newNode->prev = tail;
	tail = newNode;
	// circle connection
	head->prev = tail;
	tail->next = head;
	//
}

template<class T>
T CircularDoublyLinkedList<T>::at(int idx)
{
	if (idx < 0 || idx >= length)
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
int CircularDoublyLinkedList<T>::Length()
{
	return length;
}

template<class T>
CircularDoublyLinkedList<T>::~CircularDoublyLinkedList()
{
	Node* tmp;
	while (length--) {
		tmp = head->next;
		delete head;
		head = tmp;
	}
	tail = nullptr;
}
#endif