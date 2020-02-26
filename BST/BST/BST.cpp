#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class BST{
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
	queue<node*> qel;
	stack<node*> sel;
	int tcnt;
	int getData(node* Node) const { return Node->data; }
	void reviseData(node* Node, int datum) { Node->data = datum; }
	queue<node*> underNodes(node*);

public:
	BST();
	void insert(int);
	bool search(int);
	int del(int);
	void preOrder();
	void inOrder();
	void postOrder();
	void levelOrder();
	void dispHeight();
	void dispNodeCnt();

	//~BST();
};

BST::BST() : cur(nullptr), root(nullptr), tcnt(0) {}

queue<BST::node*> BST::underNodes(node* head) {
	queue<node*> nodes;
	if (!head) return nodes;
	while (!qel.empty()) qel.pop();
	qel.push(cur = head);
	while (qel.size()) {
		getData(cur = qel.front());
		nodes.push(qel.front());
		qel.pop();
		if (cur->left) qel.push(cur->left);
		if (cur->right) qel.push(cur->right);
	}
	return nodes;
}

void BST::insert(int datum) {
	cur = root;
	if (!root)
		root = new node(datum);
	else {
		while (1) {
			if (getData(cur) > datum) {
				if (!cur->left) {
					cur->left = new node(datum);
					break;
				}
				cur = cur->left;
			}
			else {
				if (!cur->right) {
					cur->right = new node(datum);
					break;
				}
				cur = cur->right;
			}
		}
	}
	tcnt++;
}

bool BST::search(int datum) {
	if (!root) return 0;
	cur = root;
	while (cur) {
		if (getData(cur) == datum) return 1;
		else if (getData(cur) > datum) {
			if (cur->left) cur = cur->left;
			else return 0;
		}
		else if (getData(cur) < datum) {
			if (cur->right) cur = cur->right;
			else return 0;
		}
	}
	return 0;
}

int BST::del(int datum) {
	if (!root) return -1;
	node* par, *target, *lowerNode;
	bool flag = 0;
	par  = target = root;
	while (target) {
		if (getData(target) == datum) {
			flag = 1;
			break;
		}
		if (getData(target) > datum) {
			par = target;
			if (target->left) target = target->left;
			else return -1;
		}
		else if (getData(target) < datum) {
			par = target;
			if (target->right) target = target->right;
			else return -1;
		}
	}
	lowerNode= target;
	if (flag) {
		if (!lowerNode->left && !lowerNode->right) {
			if (par->left) par->left = nullptr;
			else par->right = nullptr;
			delete lowerNode;
			
			return datum;
		}
		else {
			if (underNodes(lowerNode->left).size() < underNodes(lowerNode->right).size()) {
				lowerNode = lowerNode->right;
				while (lowerNode->left) {
					par = lowerNode;
					lowerNode = lowerNode->left;
				}
				reviseData(target, getData(lowerNode));
				delete lowerNode;
				par->left = nullptr;
				
			}
			else {
				lowerNode = lowerNode->left;
				while (lowerNode->right) {
					par = lowerNode;
					lowerNode = lowerNode->right;
				}
				reviseData(target, getData(lowerNode));
				delete lowerNode;
				par->right = nullptr;
			}
		}
		return datum;
	}
	else return -1;
}

void BST::preOrder() {
	while (!sel.empty()) sel.pop();
	sel.push(cur = root);
	cout << "preOrder: ";
	while (!sel.empty()) {
		cout << getData(cur = sel.top());
		sel.pop();
		if (cur->right) sel.push(cur->right);
		if (cur->left) sel.push(cur->left);
		if (sel.size()) cout << "-> ";
		else cout << "\n\n";
	}
}

void BST::inOrder() {
	while (!sel.empty()) sel.pop();
	sel.push(cur = root);
	cout << "inOrder: ";
	while (!sel.empty()) {
		while (cur->left) sel.push(cur = cur->left);
		cout << getData(cur = sel.top());
		sel.pop();
		if (cur->right) sel.push(cur = cur->right);
		if (!sel.empty()) cout << "-> ";
		else cout << "\n\n";
	}
}

void BST::postOrder() {
	while (!sel.empty()) sel.pop();
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
			cur = sel.top();
			sel.pop();
			if (cur->left && !cur->right && (cur->left != visited)) {
				sel.push(cur);
				cur = cur->left;
			}
			if (!cur->right || cur->right == visited) {
				cout << getData(cur);
				visited = cur;
				if (!sel.empty()) cout << "-> ";
				else cout << "\n\n";
			}
		}
		else break;
	}
}

void BST::levelOrder() {
	cout << "levelOrder: ";
	while (!qel.empty()) qel.pop();
	qel.push(cur = root);
	while (qel.size()) {
		cout << getData(cur = qel.front());
		qel.pop();
		if (cur->left) qel.push(cur->left);
		if (cur->right) qel.push(cur->right);
		if (!qel.empty()) cout << "-> ";
		else cout << "\n\n";
	}
}

void BST::dispHeight() { // using inOrder algorithm
	int level = 0, MaxDepth = 0;
	while (!sel.empty()) sel.pop();
	sel.push(cur = root);
	while (!sel.empty()) {
		while (cur->left) {
			sel.push(cur = cur->left);
			level++;
			MaxDepth = level > MaxDepth ? level : MaxDepth;
		}
		cur = sel.top();
		sel.pop();
		level--;
		if (cur->right) {
			sel.push(cur = cur->right);
			level++;
			MaxDepth = level > MaxDepth ? level : MaxDepth;
		}
	}
	cout << "Tree Height is " << MaxDepth << " (started with level 0.)\n\n";
}

void BST::dispNodeCnt() {
	cout << "Tree has " << tcnt << " nodes\n\n";
}

int main() {
	BST tt;
	for (int i = 1; i < 5; i++)
		tt.insert(i);
	cout << tt.del(2) << endl;
	tt.levelOrder();
	
}