#include <iostream>
#include <string>
using namespace std;

class Stack {
public:
	void push(int);
	int pop();
	void disp();
	~Stack();
private:
	class node {
	public:
		int data;
		node* next;
		node* prev;
		node(int n) : data(n) {
			prev = next = nullptr;
		};
	};
	node* head = nullptr;
	node* tail = nullptr;
	node* cur = nullptr; // current
	node* pre = nullptr; // prev
	int ncnt = 0; // node counter
};

void Stack::push(int n) {
	if (!ncnt) {
		head = new node(n);
		tail = head;
	}
	else if (ncnt == 1) {
		tail = new node(n);
		head->next = tail;
		tail->prev = head;
	}
	else {
		cur = tail;
		tail = new node(n);
		cur->next = tail;
		tail->prev = cur;
	}
	ncnt++;
}
int Stack::pop() {
	if (ncnt < 1) {
		cout << "Que is empty";
		return -1;
	}
	int tmp = tail->data;
	if (ncnt == 1) {
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
	ncnt--;
	return tmp;
}

void Stack::disp() {
	string msg;
	if (ncnt < 1) {
		msg = "data does not exist\n\n";
	}
	else {
		msg = "list: [ ";
		if (head == tail) {
			msg += to_string(head->data);
		}

		else {
			cur = head;
			for (int i = 0; cur; i++) {
				msg += to_string(cur->data);
				if (i < ncnt - 1) msg += ", ";
				cur = cur->next;
			}
		}
		msg += " ]\n\n";
	}
	cout << msg;
}

Stack::~Stack() {
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

int main() {
	Stack ss;
	ss.push(3);
	ss.disp();
	ss.push(34);
	ss.disp();
	ss.pop();
	ss.disp();
}
