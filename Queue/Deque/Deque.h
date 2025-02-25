#ifndef Deque_H
#define Deque_H
template<class T>
class Deque
{
	int front;
	int rear;
	int Size;
	int capacity;
	float ExpandFactor;
	T* arr;
	void Expand();
public:
	Deque();
	void enQueueFront(T x);
	void enQueueBack(T x);
	T deQueueFront();
	T deQueueBack();
	T Front();
	T Back();
	bool isEmpty();
	bool isFull();
	int size();
};
#include "Deque.cpp"
#endif

