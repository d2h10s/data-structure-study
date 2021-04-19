#include <iostream>
#include "Que.h"
#include "Stack.h"
using namespace std;

class Tree {
public:
	Tree();
	void traversal();
	void enter(int);
	void preOrder();
	void inOrder();
	void postOrder();
	void levelOrder();
	void dispHeight();
	void dispNodeCnt();

	~Tree();
private:
	class node {
	public:
		node(int n) :data(n) {
			left = right = nullptr;
		}
		int data;
		node* left;
		node* right;
	};
	node* root;
	node* cur;
	Que<node*> qel;
	Stack<node*> sel;
	int tcnt;
	int getData(node* Node) const{ return cur->data; };
};

Tree::Tree() : cur(nullptr), root(nullptr), tcnt(0) {}


void Tree::traversal() {
	int datum;
	cout << "input Root:  ";
	cin >> datum;
	root = new node(datum);
	qel.enqueue(root);
	while (1) {
		cur = qel.dequeue();
		cout << "input Left:  ";
		cin >> datum;
		cur->left = new node(datum);
		if (datum == -1) break;
		qel.enqueue(cur->left);
		cout << "input Right: ";
		cin >> datum;
		if (datum == -1) break;
		cur->right = new node(datum);
		qel.enqueue(cur->right);
	}
}
void Tree::enter(int datum) {
	if (!root) root = new node(datum);
	else {
		qel.clear();
		qel.enqueue(root);
		while (1) {
			cur = qel.dequeue();
			if (cur->left) qel.enqueue(cur->left);
			if (cur->right) qel.enqueue(cur->right);
			if (!cur->left) {
				cur->left = new node(datum);
				break;
			}
			else if (!cur->right) {
				cur->right = new node(datum);
				break;
			}
		}
	}
	tcnt++;
};

void Tree::preOrder() {
	sel.clear();
	sel.push(cur = root);
	cout << "preOrder: ";
	while (sel.size()) {
		cout << getData(cur = sel.pop());
		if (cur->right) sel.push(cur->right);
		if (cur->left) sel.push(cur->left);
		if (sel.size()) cout << "-> ";
		else cout << "\n\n";
	}
}

void Tree::inOrder() {
	sel.clear();
	sel.push(cur = root);
	cout << "inOrder: ";
	while (sel.size()) {
		while (cur->left) sel.push(cur = cur->left);
		cout << getData(cur = sel.pop());
		if (cur->right) sel.push(cur = cur->right);
		if (sel.size()) cout << "-> ";
		else cout << "\n\n";
	}
}

void Tree::postOrder() {
	sel.clear();
	node* visited = nullptr;
	cur = root;
	cout << "postOrder: ";
	while (1) {
		if (cur && (cur != visited)) {
			sel.push(cur);
			while (cur->left) {
				if (cur->right) sel.push(cur->right);
				if (cur->left) sel.push(cur = cur->left);
			}
		}
		if (sel.size()) {
			cur = sel.pop();
			if (cur->left && !cur->right && (cur->left != visited)) {
				sel.push(cur);
				cur = cur->left;
			}
			if (!cur->right || cur->right == visited) {
				cout << getData(cur);
				visited = cur;
				if (sel.size()) cout << "-> ";
				else cout << "\n\n";
			}
		}
		else break;
	}
}

void Tree::levelOrder() {
	cout << "levelOrder: ";
	qel.clear();
	qel.enqueue(cur = root);
	while (qel.size()) {
		cout << getData(cur = qel.dequeue());
		if (cur->left) qel.enqueue(cur->left);
		if (cur->right) qel.enqueue(cur->right);
		if (qel.size()) cout << "-> ";
		else cout << "\n\n";
	}
}

void Tree::dispHeight() { // using inOrder algorithm
	int level = 0, MaxDepth = 0;
	sel.clear();
	sel.push(cur = root);
	cout << "inOrder: ";
	while (sel.size()) {
		while (cur->left) {
			sel.push(cur = cur->left);
			level++;
			MaxDepth = level > MaxDepth ? level : MaxDepth;
		}
		cur = sel.pop();
		level--;
		if (cur->right) {
			sel.push(cur = cur->right);
			level++;
			MaxDepth = level > MaxDepth ? level : MaxDepth;
		}
	}
	cout << "Tree Height is " << MaxDepth << " (started with level 0.)\n\n";
}

void Tree::dispNodeCnt() {
	cout << "Tree has " << tcnt << " nodes\n\n";
}

Tree::~Tree() {
	qel.clear();
	sel.clear();
}


int main() {
	Tree tt;
	for(int i = 1; i <= 15; i++)
		tt.enter(i);
	tt.preOrder();
	tt.inOrder();
	tt.postOrder();
	tt.levelOrder();
	tt.dispNodeCnt();
	tt.dispHeight();
}