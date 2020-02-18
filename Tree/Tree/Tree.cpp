#include <iostream>
#include "Que.h"
#include "Stack.h"
using namespace std;

class Tree {
public:
	Tree();
	void traversal();
	void ent(int);
	void preOrder();
	void inOrder();
	void postOrder();
	void levelOrder();

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
	int ncnt;
	int getData(node* Node) const{ return cur->data; };
};

Tree::Tree() : cur(nullptr), root(nullptr), ncnt(0) {}


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
void Tree::ent(int datum) {
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
	ncnt++;
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
		else cout << endl;
	}
}

void Tree::inOrder() {
	sel.clear();
	sel.push(cur = root);
	cout << "inOrder: ";
	while (sel.size()) {
		cout << getData(cur = sel.pop());
		if (cur->right) sel.push(cur->right);
		if (cur->left) sel.push(cur->left);
		if (sel.size()) cout << "-> ";
		else cout << endl;
	}
}

void Tree::postOrder() {
	cout << "postOrder: ";
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
		else cout << endl;
	}
}

Tree::~Tree() {

}


int main() {
	Tree tt;
	for(int i = 1; i <= 15; i++)
		tt.ent(i);
	tt.preOrder();
	tt.levelOrder();
}