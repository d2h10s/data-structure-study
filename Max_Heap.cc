#include<iostream>
using namespace std;

template <class T>
class tree {
    class node {
    public:
        node(T datum) :data(datum) {}
        T data = NULL;
        node* left = nullptr;
        node* right = nullptr;
    };
    node* head = nullptr, * cur = nullptr;
public:
    ~tree(){
        del(head);
    }
    void del(node* n){
        if (n == nullptr) return;
        del(n->left);
        del(n->right);
        delete n;
    }
    void input(T datum) {
        if (!head) {
            head = new node(datum);
            return;
        }
        cur = head;
        while (true) {
            if (cur->data < datum) {
                if (cur->right) cur = cur->right;
                else {
                    cur->right = new node(datum);
                    break;
                }
            }
            else {
                if (cur->left) cur = cur->left;
                else {
                    cur->left = new node(datum);
                    break;
                }
            }
        }
    }
    bool exist(T datum) {
        cur = head;
        while (true) {
            if (cur == nullptr) return false;
            else if (cur->data == datum) return true;
            else if (cur->data < datum) cur = cur->right;
            else cur = cur->left;
        }
    }
};

int main(int argc, char** argv)
{
    return 0;
}