#include <iostream>
#define MAX 10001
using namespace std;

typedef struct Node{
    int key;
    Node * left;
    Node * right;
} Node;

Node * insert(Node * node, int key){
    if(node == NULL){
        node = new Node();
        node -> key = key;
        node -> left = node -> right = NULL;
    }
    else if(key <= node -> key) node -> left = insert(node->left, key);
    else node -> right = insert(node->right, key);
    return node;
}

void postorder(Node * node){
    if(node -> left != NULL) postorder(node->left);
    if(node-> right != NULL) postorder(node -> right);
    cout << node -> key << '\n';
}

int main(){
    int val;
    Node * Root = NULL;
    while(cin >> val){
        if(val == EOF) break;
        Root = insert(Root, val);
    }
    postorder(Root);
}