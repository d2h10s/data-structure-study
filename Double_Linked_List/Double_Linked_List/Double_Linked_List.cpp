#include <iostream>
#include <string>
using namespace std;

class list {
public:
	class node {
	private:
		friend list;
		int data;
		node* next;
		node* prev;
	public:
		node(int n = 0) : data(n) {
			next = prev = nullptr;
		};
		int getData() const {
			return data;
		}
		void putData(int n) {
			data = n;
		}
	};

	list(int n) {
		head = new node;
		tail = new node(n);
		head->next = tail;
		tail->prev = head;
		nodecnt++;
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
	void circulate(int index);
	bool isCircul();
	string sort();
	string sorted();
	string disp();
	string dispRev();

private:
	node* head = nullptr;
	node* tail = nullptr;
	node* cur = nullptr;
	node* pre = nullptr;
	int nodecnt{ 0 };
};

void list::addFirst(int datum) {
	node* newlist = new node(datum);
	cur = head->next;
	cur->prev = newlist;
	head->next = newlist;
	newlist->next = cur;
	newlist->prev = head;
	nodecnt++;
}
void list::addLast(int datum) {
	node* newlist = new node(datum);
	if (nodecnt == 0) {
		addFirst(datum);
		nodecnt++;
		return;
	}
	tail->next = newlist;
	newlist->prev = tail;
	tail = newlist;
	nodecnt++;
}

void list::addIdx(int index, int datum) {
	if (index > nodecnt) {
		cout << "out of index\n\n";
		return;
	}
	else if (index == nodecnt) {
		addLast(datum);
		return;
	}
	node* newlist = new node(datum);
	pre = head;
	for (int i = 0; i < index; i++)
		pre = pre->next; // 인덱스 앞까지 서치
	cur = pre->next;
	pre->next = newlist;
	cur->prev = newlist;
	newlist->next = cur;
	newlist->prev = pre;
	nodecnt++;
}

int list::removeFirst() {
	if (nodecnt < 1) {
		cout << "there is no data\n\n";
		return -1;
	}
	int tmp = head->next->getData();
	if (nodecnt == 1) {
		tail->data = NULL;
		nodecnt--;
		return tmp;
	}
	pre = head->next;
	cur = head->next->next;
	delete pre;
	head->next = cur;
	cur->prev = head;
	nodecnt--;
	return tmp;
}

int list::removeLast() {
	cur = head;
	if (nodecnt < 1) {
		cout << "there is no data\n\n";
		return -1;
	}
	int tmp = tail->getData();
	if (nodecnt == 1) {
		return removeFirst();
	}
	pre = tail->prev;
	delete tail;
	tail = pre;
	tail->next = nullptr;
	nodecnt--;
	return tmp;
}

int list::removeIdx(int index) {
	if (nodecnt < 1) {
		cout << "there is no data\n\n";
		return -1;
	}
	if (nodecnt - 1 < index || index < 0) {
		cout << "out of index\n\n";
		return -1;
	}
	else if (index == nodecnt - 1) {
		return removeLast();
	}
	pre = head;
	for (int i = 0; i < index; i++)
		pre = pre->next;
	cur = pre->next->next;
	int tmp = pre->next->getData();
	delete pre->next;
	pre->next = cur;
	cur->prev = pre;
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

void list::circulate(int index) {
	cur = head;
	for (int i = 0; i <= index; i++)
		cur = cur->next;
	tail->next = cur;
}

bool list::isCircul() {
	node* p = head;
	node* q = head;
	do {
		if (q->next == nullptr || p->next == nullptr || p->next->next == nullptr) return false;
		q = q->next;
		p = p->next->next;
	} while (p != q);
	return true;
}

string list::sort() {
	string msg;
	return msg;
}

string list::sorted() {
	string msg;
	return msg;
}

string list::disp() {
	string msg;
	if (nodecnt < 1) {
		msg.append("data does not exist\n\n");
		return msg;
	}
	msg = "list: [ ";
	cur = head;
	for (int i = 0; i < nodecnt; i++) {
		cur = cur->next;
		msg += to_string(cur->getData());
		if (i < nodecnt - 1) msg += ", ";
	}
	msg += " ]\n\n";
	return msg;
}

string list::dispRev() {
	string msg;
	if (nodecnt < 1) {
		msg.append("data does not exist\n\n");
		return msg;
	}
	msg = "list: [ ";
	cur = tail;
	for (int i = 0; i < nodecnt; i++) {
		msg += to_string(cur->getData());
		if (i < nodecnt - 1) msg += ", ";
		cur = cur->prev;
	}
	msg += " ]\n\n";
	return msg;
}

int main() {
	list tt(1);
	tt.addFirst(3);
	tt.addLast(2);

	cout << tt.disp();
	tt.removeIdx(2);
	//tt.removeFirst();
	//tt.removeLast();
	cout << tt.disp();
	cout << tt.dispRev();
}
