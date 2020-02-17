#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Stack {
public:
	void push(T);
	T pop();
	void disp();
	~Stack();
private:
	class node {
	public:
		T data;
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
};

template <class T>
void Stack<T>::push(T datum) {
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
T Stack<T>::pop() {
	T tmp = tail->data;
	if (ncnt < 1) {
		cout << "Que is empty";
	}
	else if (ncnt == 1) {
		delete tail;
	}
	else if (ncnt == 2) {
		delete tail;
		tail = head;
	}
	else {
		cur = tail->prev;
		delete tail;
		tail = cur;
		tail->next = nullptr;
	}
	if(ncnt) ncnt--;
	return tmp;
}

template <class T>
void Stack<T>::disp() {
	if (ncnt < 1) {
		cout << "data does not exist\n\n";
	}
	else {
		cout << "list: [ ";
		if (head == tail) {
			cout << head->data;
		}
		else {
			cur = head;
			for (int i = 0; cur; i++) {
				cout << cur->data;
				if (i < ncnt - 1) cout << ", ";
				cur = cur->next;
			}
		}
		cout << " ]\n\n";
	}
}

template <class T>
Stack<T>::~Stack() {
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