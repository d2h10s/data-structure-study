#include <iostream>
#include <string>
using namespace std;

class list {

public:
	class node {
	public:
		int data;
		node* next;
		node(int n = 0) : data(n), next(nullptr) {};
		int getData() const {
			return data;
		}
		void putData(int n) {
			data = n;
		}
	};

	list() {
		head = new node{ 0 };
		head->next = tail;
	}
	~list() {
		node* temp = head->next;
		for (int i = 0; i < nodecnt; i++) {
			temp = head->next;
			delete head;
			head = temp;
		}

	}
	void addFirst(int datum);
	void addLast(int datum);
	void addIdx(int index, int datum);
	int removeFirst();
	int removeLast();
	int removeIdx(int index);
	int nodesize();
	int getIdx(int index);
	string showSorted();
	string doSort();
	string display();

private:
	node* head = nullptr;
	node* tail = nullptr;
	node* cur = nullptr;
	int nodecnt = 0;
};

void list::addFirst(int datum) {
	node* newlist = new node(datum);
	cur = head->next;
	head->next = newlist;
	newlist->next = cur;
	nodecnt++;
}
void list::addLast(int datum) {
	node* newlist = new node(datum);
	cur = head;
	while (cur->next != nullptr)
		cur = cur->next;
	tail = newlist;
	cur->next = tail;
	nodecnt++;
}

void list::addIdx(int index, int datum) {
	if (index > nodecnt) {
		cout << "out of index\n\n";
		return;
	}
	else if (index == nodecnt) {
		node* newlist = new node(datum);
		cur = head;
		for (int i = 0; i < index - 1; i++)
			cur = cur->next;
		tail = newlist;
		newlist->next = nullptr;
		cur->next = newlist;
		nodecnt++;
		return;
	}
	node* newlist = new node(datum);
	cur = head;
	for (int i = 0; i < index; i++)
		cur = cur->next;
	newlist->next = cur->next;
	cur->next = newlist;
	nodecnt++;
}

int list::removeFirst() {
	int tmp = head->next->getData();
	node* temp = head->next;
	head->next = head->next->next;
	delete temp;
	nodecnt--;
	return tmp;
}

int list::removeLast() {
	int tmp = tail->getData();
	node* temp;
	cur = head;
	if (nodecnt <= 1) {
		delete tail;
		tail = nullptr;
		head->next = tail;
		nodecnt--;
		return tmp;
	}

	for (int i = 0; i < nodecnt - 1; i++) {
		temp = cur;
		cur = cur->next;
	}
	delete tail;
	tail = cur;
	temp = tail;
	tail->next = nullptr;
	nodecnt--;
	return tmp;
}

int list::removeIdx(int index) {
	if (nodecnt - 1 < index) {
		cout << "out of index\n\n";
		return -1;
	}
	else if (index == nodecnt - 1) {
		return removeLast();
	}
	cur = head;
	for (int i = 0; i < index; i++)
		cur = cur->next;
	node* temp = cur->next;
	int tmp = temp->getData();
	cur->next = cur->next->next;
	delete temp;
	nodecnt--;
	return tmp;
}

int list::nodesize() {
	return nodecnt;
}

int list::getIdx(int index) {
	if (index > nodecnt - 1) {
		cout << "out of index\n\n";
		return -1;
	}
	cur = head;
	for (int i = 0; i <= index; i++)
		cur = cur->next;
	return cur->getData();
}

string list::showSorted() {
	string msg;
	return msg;
}

string list::doSort() {
	string msg;
	return msg;
}

string list::display() {
	string msg;
	if (nodecnt == 0) {
		msg.append("data does not exist");
		return msg;
	}
	cur = head;
	for (int i = 0; cur->next != nullptr; i++) {
		cur = cur->next;
		msg += to_string(cur->getData());
		if (cur->next != nullptr) msg += ", ";
	}
	msg += "\n\n";
	return msg;
}

int main() {
	list test;
	test.addLast(1);
	cout << test.display();

	test.addFirst(8);
	cout << test.display();

	test.addIdx(1, 9);
	cout << test.display();

	cout << "node size is " << test.nodesize() << "\n\n";
	cout << "You poped last member who " << test.removeLast() << "\n\n";
	cout << test.display();

	test.addFirst(724);
	test.addFirst(33);
	cout << test.display();

	cout << "node size is " << test.nodesize() << "\n\n";
	cout << "You poped a member who " << test.removeIdx(0) << "\n\n";
	cout << test.display();

	test.addIdx(3, 2);
	cout << test.display();

	cout << "index 2 has " << test.getIdx(4) << endl;
}
