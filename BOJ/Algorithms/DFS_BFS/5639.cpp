#include <iostream>
#define MAX 10001
using namespace std;

typedef struct Node{
    int data;
    Node * left;
    Node * right;
} Node;

Node * insert(Node * node, int data){
    if(node == NULL){
        node = new Node();
        node -> data = data;
        node -> left = node -> right = NULL;
    }
    else if(data <= node -> data) node -> left = insert(node->left, data);
    else node -> right = insert(node->right, data);
    return node;
}


int main(){
    int val;
    while(cin >> val){
        if(val == EOF) break;
    }

}