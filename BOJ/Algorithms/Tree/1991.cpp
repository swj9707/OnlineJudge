#include <iostream>

using namespace std;
typedef struct _node{
    _node * left;
    _node * right;
    char value;
} node;

void preorder(node * n){
    cout << n->value;
    if(n->left != NULL) preorder(n->left);
    if(n->right != NULL) preorder(n->right);
}
void inorder(node * n){
    if(n->left != NULL) inorder(n->left);
    cout << n-> value;
    if(n->right != NULL) inorder(n->right);
}
void postorder(node *n){
    if(n->left != NULL) postorder(n->left);
    if(n->right != NULL) postorder(n->right);
    cout << n->value;
}

int main(){

}