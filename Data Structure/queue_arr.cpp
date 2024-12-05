#include <iostream>
using namespace std;

template<typename T>
class Queue {
private:
	T* arr;
	int capacity; int size;
	int front; int rear;
public:
	Queue(int capacity) : capacity(capacity), size(0), front(0), rear(-1) {
		arr = new T[capacity];
	}
	~Queue() {
		delete[] arr;
	}

	bool isEmpty() {
		return size == 0;
	}

	bool isFull() {
		return size == capacity;
	}

	void enqueue(const T& item) {
		if (isFull())
			throw overflow_error("Queue is full");
		rear = (rear + 1) % capacity;
		arr[rear] = item;
		size++;
	}

	T dequeue() {
		if (isEmpty())
			throw underflow_error("Queue is empty");
		T item = arr[front];
		front = (front + 1) % capacity;
		size--;
		return item;
	}

	T peek() {
		if (isEmpty()) {
			throw underflow_error("Queue is empty");
		}
		return arr[front];
	}
};
