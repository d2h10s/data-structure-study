#include <iostream>


class Tree {
public:
	Tree(int);
	void ent(int);
	void preDisp();
	void inDisp();
	void postDisp();
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
	int recur(int, int, int);
	node* root;
	node* cur;
	node* par;
	node* sib;
	int ncnt{ 1 };
};

Tree::Tree(int n){
	root = new node(n);
}

int Tree::recur(int n, int lev = 0, int dir = 0) {
	if (!cur->left) return 0;
	else if (!cur->right) return 1;
	if (dir == 0) cur = cur->left;
	else cur = cur->right;
	lev++;
	recur(n, lev, 0);
	recur(n, lev, 1);
	lev--;
}


void Tree::ent(int n) {
	cur = root;
	if (!recur(n, 0, 0)) cur->left = new node(n);
	else cur->right = new node(n);
	ncnt++;
};

void Tree::preDisp() {
	using namespace std;
}

void Tree::inDisp() {
	using namespace std;
}

void Tree::postDisp() {
	using namespace std;
}

Tree::~Tree() {

}

int main() {
	Tree tt(1);
	tt.ent(2);
	tt.ent(3);
	tt.ent(4);
	tt.ent(5);
	tt.ent(6);
}