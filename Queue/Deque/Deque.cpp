#ifndef Deque_CPP
#define Deque_CPP
#include "Deque.h"
#include<iostream>
using namespace std;
template<class T>
Deque<T>::Deque() {

	front = rear = -1;
	Size = 0;
	capacity = 2;
	ExpandFactor = 1.5;
	arr = new T[capacity];
}

template<class T>
void Deque<T>::Expand()
{
	int prevCapacity = capacity;
	capacity *= ExpandFactor;
	T* newArr = new T[capacity];
	int idx = 0;
	while (front != rear) {
		newArr[idx] = arr[front];
		front = (front + 1) % prevCapacity;
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
void Deque<T>::enQueueFront(T x)
{
	if (isFull()) {
		Expand();
	}
	front = ((front - 1) % capacity+capacity)%capacity;
	arr[front] = x;
	if (isEmpty())
		rear = front;
	Size++;
}

template <class T>
void Deque<T>::enQueueBack(T x)
{
	if (isFull()) {
		Expand();
	}
	rear = (rear+1)%capacity;
	arr[rear] = x;
	if (isEmpty())
		front = rear;
	Size++;
}

template<class T>
T Deque<T>::deQueueFront()
{
	if (isEmpty()) {
		cout << "Error : Queue already empty" << endl;
		return T();
	}
	T temp = Front();
	front = (front + 1) % capacity;
	Size--;
	if (isEmpty()) {
		front = rear = -1;
	}
	return temp;
}

template <class T>
T Deque<T>::deQueueBack()
{
	if (isEmpty()) {
		cout << "Error : Queue already empty" << endl;
		return T();
	}
	T temp = Back();
	rear = ((rear - 1) % capacity+capacity)%capacity;
	Size--;
	if (isEmpty()) {
		front = rear = -1;
	}
	return temp;
}
template<class T>
T Deque<T>::Front()
{
	return arr[front];
}

template <class T>
T Deque<T>::Back()
{
	return arr[rear];
}

template<class T>
bool Deque<T>::isEmpty()
{
	return Size == 0;
}

template<class T>
bool Deque<T>::isFull()
{
	return Size == capacity;
}

template<class T>
int Deque<T>::size() {
	return Size;
}

#endif