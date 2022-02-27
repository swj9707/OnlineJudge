#include <iostream>
#define MAX 500001
using namespace std;

int Parent[MAX];

int getParent(int num){
    if(num == Parent[num]) return num;
    return Parent[num] = getParent(Parent[num]);
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a != b) Parent[a] = b;
}

bool findParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a == b) return true;
    else return false;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    int answer = 0;
    for(int i = 0; i < MAX; i++) Parent[i] = i;
    for(int i = 1; i <= M; i++){
        int U, V;
        cin >> U >> V;
        if(!findParent(U, V)){
            unionParent(U, V);
        }
        else {
            answer = i;
            break;
        }
    }
    cout << answer << '\n';
}