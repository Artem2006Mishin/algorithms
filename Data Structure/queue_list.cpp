#include <iostream>
using namespace std;

template<typename T>
struct Node {
	T data;
	Node* next;

	Node(const T& value) : data(value), next(nullptr) {}
};

template<typename T>
class Queue {
private:
	Node<T>* front;
	Node<T>* rear;
	int size;
public:
	Queue() : front(nullptr), rear(nullptr), size(0) {}

	~Queue() {
		clear();
	}

	bool isEmpty() const {
		return size == 0;
	}

	void enqueue(const T& value) {
		Node<T>* newNode = new Node(value);
		if (isEmpty()) {
			front = rear = newNode;
		}
		else {
			rear->next = newNode;
			rear = rear->next;
		}
		size++;
	}

	T dequeue() {
		if (isEmpty()) 
			throw underflow_error("Queue is empty");
		T data = front->data;
		Node<T>* temp = front;
		front = front->next;
		delete temp;
		size--;
		if (isEmpty())
			rear = nullptr;
		return data;
	}

	T peek() const {
		if (isEmpty()) {
			throw underflow_error("Queue is empty");
		}
		return front->data;
	}

	// Function to get the size of the queue
	int getSize() const {
		return size;
	}

	// Function to clear the queue
	void clear() {
		while (!isEmpty()) {
			dequeue();
		}
	}
};
