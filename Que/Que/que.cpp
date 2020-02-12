#include <iostream>
#include <string>
using namespace std;

class Que {
public:
	void enqueue(int);
	int dequeue();
	void disp();
	~Que();
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

void Que::enqueue(int n) {
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
int Que::dequeue() {
	if (ncnt < 1) {
		cout << "Que is empty";
		return -1;
	}
	int tmp = head->data;
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

void Que::disp() {
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

Que::~Que() {
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
	Que que;
	que.enqueue(3);
	que.enqueue(2);
	que.disp();
	que.dequeue();
	que.disp();
}