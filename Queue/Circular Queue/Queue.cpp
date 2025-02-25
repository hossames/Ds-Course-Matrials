#ifndef Queue_CPP
#define Queue_CPP
#include "Queue.h"
#include<iostream>
using namespace std;
template<class T>
Queue<T>::Queue()
{
	front = rear = -1;
	Size = 0;
	capacity = 2;
	ExpandFactor = 1.5;
	arr = new T[capacity];
}

template<class T>
void Queue<T>::Expand()
{
	int prevCapacity = capacity;
	capacity *= ExpandFactor;
	T* newArr = new T[capacity];
	int idx = 0;
	while (front != rear) {
		newArr[idx] = arr[front];
		front = (front + 1)%prevCapacity;
		idx++;
	}
	newArr[idx] = arr[front];
	front = 0;
	rear = Size - 1;
	delete[] arr;
	arr = newArr;
	newArr = nullptr;
}

template<class T>
void Queue<T>::enQueue(T x)
{
	if (isFull()) {
		Expand();
	}
	if (isEmpty())
		front = 0;
	rear = (rear + 1) % capacity;
	arr[rear] = x;
	Size++;
}

template<class T>
T Queue<T>::deQueue()
{
	if (isEmpty()) {
		cout << "Error : Queue already empty" << endl;
		return T();
	}
	T temp = peek();
	front =(front+1)%capacity;
	Size--;
	if (isEmpty()) {
		front = rear = -1;
	}
	return temp;
}

template<class T>
T Queue<T>::peek()
{
	return arr[front];
}

template<class T>
bool Queue<T>::isEmpty()
{
	return Size == 0;
}

template<class T>
bool Queue<T>::isFull()
{
	return Size == capacity;
}

template<class T>
int Queue<T>::size() {
	return Size;
}

#endif