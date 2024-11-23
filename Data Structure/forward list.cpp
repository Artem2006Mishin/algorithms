#include <iostream> 

using namespace std;

// реализация узла:
struct Node 
{
	string val;
	Node* next;
	Node(string _val) : val(_val), next(nullptr) {}
};

// создание списка: 
struct list
{
	Node* first;
	Node* last;

	list() : first(nullptr), last(nullptr) {}

	// функция проверки наличия узлов в списке:
	bool is_empty() {
		return first == nullptr;
	}

	// функция добавления элемента в конец списка:
	void push_back(string _val) {
		Node* p = new Node(_val);
		if (is_empty()) {
			first = p;
			last = p;
			return;
		}
		last->next = p;
		last = p;
	}

	// функция печати всего списка:
	void print() {
		if (is_empty()) return;
		Node* p = first;
		while (p != nullptr) {
			cout << p->val << " ";
			p = p->next;
		}
	}

	// функция поиска узла в списке по заданному значению:
	Node* find(string _val)
	{
		if (is_empty()) return;
		Node* p = first;
		while (p != nullptr && p->val != _val) {
			p = p->next;
		}
		return (p != nullptr && p->val == _val) ? p : nullptr;
	}

	// функция удаления первого узла:
	void remove_first()
	{
		if (is_empty()) return;
		Node* p = first;
		first = p->next;
		delete p;
	}

	// функция удаления последнего узла:
	void remove_last() 
	{
		if (is_empty()) return;
		if (first == last) {
			remove_first();
			return;
		}

		Node* p = first;
		while (p->next != last) {
			p = p->next;
		}
		p->next = nullptr;
		delete last;
		last = p;
	}

	// функция удаления узла по заданному значению значению:
	void remove(string _val)
	{
		if (is_empty()) return;
		if (_val == first->val) {
			remove_first(); 
			return;
		}
		else if (_val == last->val) {
			remove_last();
			return;
		}

		Node* slow = first;
		Node* fast = slow->next;
		while (fast != nullptr && fast->val != _val) {
			fast = fast->next;
			slow = slow->next;
		}
		if (fast == nullptr) {
			cout << "This element does not exist" << endl;
			return;
		}
		slow->next = fast->next;
		delete fast;
	}

	// функция обращения к узлу по индексу:
	Node* operator[] (const int index)
	{
		if (is_empty()) return nullptr;
		Node* p = first;
		for (int i = 0; i < index; i++) {
			p = p->next;
			if (!p) return nullptr;
		}
		return p;
	}
};
