#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <class T>
class Node {
public:
	vector<Node<T>> neighbors;
	vector<int> weight;
	T Data;
	Node(){ }
	Node(T value) {
		Data = value;
	}
};

template <class T>
class Graph {
	vector<T> NodeList;
public:
	Node<T> AddNode(Node<T> node){
		NodeList.push_back(node);
		return node;
	}
	void AddEdge(Node<T> from, Node<T> to, bool oneway = true, int weight = 0) {
		from.neighbors.push_back(to);
		from.weight.push_back(weight);
		if (!oneway) {
			to.neighbors.push_back(from);
			to.weight.push_back(weight);
		}
	}
	void kruskal() {
		priority_queue<T, vector<T>, greater<T>> pq;
		for (int i = 0; i < NodeList.size(); i++) {
			pq.push();
		}
	}
};