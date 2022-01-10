#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001
using namespace std;

int N, M;
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
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) Parent[i] = i;
    for(int i = 0; i < M; i++){
        int num, a, b;
        cin >> num >> a >> b;
        if(num == 0) unionParent(a, b);
        else if(num == 1){
            if(findParent(a, b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}