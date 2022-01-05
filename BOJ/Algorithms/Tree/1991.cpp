#include <iostream>

using namespace std;

pair<int, int> node[26];

void preorder(char current){
    if(current == '.') return;
    cout << current;
    preorder(node[current - 'A'].first);
    preorder(node[current - 'A'].second);
}

void inorder(char current){
    if(current == '.') return;
    inorder(node[current - 'A'].first);
    cout << current;
    inorder(node[current - 'A'].second);
}

void postorder(char current){
    if(current == '.') return;
    postorder(node[current - 'A'].first);
    postorder(node[current - 'A'].second);
    cout << current;
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        char ch, left, right;
        cin >> ch >> left >> right;
        node[ch - 'A'] = {left, right};
    }
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    cout << '\n';
}