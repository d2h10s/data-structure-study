#include <iostream>
#include "Que.h"
#include "Stack.h"

class Tree {
public:
	Tree();
	void traversal();
	void ent(int);
	void preOrder();
	void inOrder();
	void postOrder();

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
	Que<node*> el;
	int ncnt;
	int getData(node* Node) const{ return cur->data; };
};

Tree::Tree() : cur(nullptr), root(nullptr), ncnt(0) {}


void Tree::traversal() {
	int datum;
	cout << "input Root:  ";
	cin >> datum;
	root = new node(datum);
	el.enqueue(root);
	while (1) {
		cur = el.dequeue();
		cout << "input Left:  ";
		cin >> datum;
		cur->left = new node(datum);
		if (datum == -1) break;
		el.enqueue(cur->left);
		cout << "input Right: ";
		cin >> datum;
		if (datum == -1) break;
		cur->right = new node(datum);
		el.enqueue(cur->right);
	}
}
void Tree::ent(int datum) {
	if (!root) root = new node(datum);
	else {
		while (el.size()) el.dequeue();
		el.enqueue(root);
		while (1) {
			cur = el.dequeue();
			if (cur->left) el.enqueue(cur->left);
			if (cur->right) el.enqueue(cur->right);
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
	using namespace std;
}

void Tree::inOrder() {
	using namespace std;
}

void Tree::postOrder() {
	using namespace std;
}

Tree::~Tree() {

}

int main() {
	Tree tt;
	tt.traversal();
	for(int i = 1; i<10; i++)
		tt.ent(i);
}