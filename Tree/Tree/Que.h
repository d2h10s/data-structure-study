#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Que {
public:
	void enqueue(T);
	T dequeue();
	void disp();
	~Que();
private:
	class node {
	public:
		int data;
		node* next;
		node* prev;
		node(T datum) : data(datum) {
			prev = next = nullptr;
		};
	};
	node* head = nullptr;
	node* tail = nullptr;
	node* cur = nullptr; // current
	node* pre = nullptr; // prev
	int ncnt = 0; // node counter
	T getData(node*);
};

template <class T>
T Que<T>::getData(node* Node) {
	return Node->data;
}

template <class T>
void Que<T>::enqueue(T datum) {
	if (!ncnt) {
		head = new node(datum);
		tail = head;
	}
	else if (ncnt == 1) {
		tail = new node(datum);
		head->next = tail;
		tail->prev = head;
	}
	else {
		cur = tail;
		tail = new node(datum);
		cur->next = tail;
		tail->prev = cur;
	}
	ncnt++;
}

template <class T>
T Que<T>::dequeue() {
	if (ncnt < 1) {
		cout << "Que is empty";
		return -1;
	}
	T tmp = getData(head);
	if (ncnt == 1) {
		delete head;
	}
	else if (ncnt == 2) {
		delete head;
		head = tail;
	}
	else {
		cur = head->next;
		delete head;
		head = cur;
	}
	ncnt--;
	return tmp;
}

template <class T>
void Que<T>::disp() {
	if (ncnt < 1) {
		cout << "data does not exist\n\n";
	}
	else {
		cout << "list: [ ";
		if (head == tail) {
			cout << getData(head);
		}

		else {
			cur = head;
			for (int i = 0; cur; i++) {
				cout << getData(cur);
				if (i < ncnt - 1) cout << ", ";
				cur = cur->next;
			}
		}
		cout << " ]\n\n";
	}
}

template <class T>
Que<T>::~Que() {
	if (ncnt == 1) {
		delete head;
		return;
	}
	for (int i = 0; i < ncnt; i++) {
		if (!head->next) {
			delete head;
			return;
		}
		cur = head->next;
		delete head;
		head = cur;
	}
}