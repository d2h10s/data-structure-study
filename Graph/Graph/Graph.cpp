#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void BFS(int mat[][8], int start);
void DFS(int mat[][8], int start);

int main() {
	int i, adMat[8][8] = { {0,0,0,0,0,0,0,0}, {0,0,1,1,1,0,0,0}, {0,1,0,1,0,0,0,0}, {0,1,1,0,1,1,0,0},{0,1,0,1,0,1,0,0},{0,0,0,1,1,0,1,1},{0,0,0,0,0,1,0,0,},{0,0,0,0,0,1,0,0} };
	for (i = 1; i < 8; i++) {
		for (int j = 1; j < 8; j++)
			printf("%d ", adMat[i][j]);
		cout << endl;
	}
	cout << endl;
	for(i = 1 ; i<8;i++)
		BFS(adMat, i);
}

void BFS(int mat[][8], int start) {
	queue<int> qel;
	int now, i;
	bool visited[8]{ 0 };
	
	visited[start] = true;
	qel.push(start);

	cout << "BFS: ";
	while (!qel.empty()) {
		now = qel.front();
		qel.pop();
		cout << now;
		for (i = 0; i < 8; i++) {
			if (mat[now][i] && !visited[i]) {
				qel.push(i);
				visited[i] = true;
			}
		}
		if (!qel.empty()) cout << " -> ";
	}
	cout << endl << endl;
}

void DFS(int mat[][8], int start) {
	stack<int> sel;

}