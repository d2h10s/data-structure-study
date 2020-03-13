#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void disp(vector<int> tmp) {
	while (!tmp.empty()) {
		cout << tmp.front();
		tmp.erase(tmp.begin());
		if (!tmp.empty()) cout << " -> ";
	}
	cout << endl << endl;
}

void swap(vector<int>& tree, int v1, int v2) {
	int tmp = tree[v1];
	tree[v1] = tree[v2];
	tree[v2] = tmp;
}

void heapSort(vector<int> tree) {
	int i;
	vector<bool> visited(tree.size());
	stack<int> ss;
	ss.push(0);
	while (!ss.empty()) {
		i = ss.top();
		visited[i] = 1;
		ss.pop();
		if (i * 2 + 1 < (tree.size() + 1) / 2 - 1 && !visited[i * 2 + 1]) ss.push(i * 2 + 1);
		if (i * 2 + 2 < (tree.size() + 1) / 2 - 1 && !visited[i * 2 + 2]) ss.push(i * 2 + 2);
		if (tree.at(i) < tree.at(i * 2 + 1)) swap(tree, i, i * 2 + 1);
		else if (tree.at(i) < tree.at(i * 2 + 2)) swap(tree, i, i * 2 + 2);
		disp(tree);
	}
}

int main() {
	vector<int> answer{ 11,33,7,9,27,65,3,1,99,56,74 };
	disp(answer);
	heapSort(answer);
	//disp(answer);
}