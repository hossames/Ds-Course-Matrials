#ifndef Queue_H
#define Queue_H
template<class T>
class Queue
{
	int front;
	int rear;
	int Size;
	int capacity;
	float ExpandFactor;
	T* arr;
	void Expand();
public:
	Queue();
	void enQueue(T x);
	T deQueue();
	T peek();
	bool isEmpty();
	bool isFull();
	int size();
};
#include "Queue.cpp"
#endif

