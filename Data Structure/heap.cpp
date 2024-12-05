#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
	vector<int> heap;

	// поменять местамиэлементы
	void swap(int& a, int& b) {
		int temp = a;
		a = b; b = temp;
	}

	// провести отсеивание после вставки
	/// изначально index - последний элемент
	void heapifyUp(int index) {
		while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
			swap(heap[index], heap[(index - 1) / 2]);
			index = (index - 1) / 2; // получение родителя
		}
	}

	// провести отсеивание после удаления
	/// изначально index - первый элемент
	void heapifyDown(int index) {
		int n = heap.size();
		int largest = index; // наш текущий родитель (изначально root)
		int left = index * 2 + 1; // левый дочерний
		int right = index * 2 + 2; // правый дочерний

		// возможно: порядок проверок важен!
		if (left < n && heap[left] > heap[largest])
			largest = left;
		if (left < n && heap[left] > heap[largest])
			largest = left;
		
		if (largest != index) {
			swap(heap[index], heap[largest]);
			heapifyDown(largest);
		}
	}
public:
	Heap() {}

	void insert(int value) {
		heap.push_back(value);
		heapifyUp(heap.size() - 1);
	}

	int extractMax() {
		if (heap.empty())
			throw runtime_error("Heap is empty");

		int maxVal = heap[0];
		heap[0] = heap.back();
		heap.pop_back();
		heapifyDown(0);
		return maxVal;
	}
};
