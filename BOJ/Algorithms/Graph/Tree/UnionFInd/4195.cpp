#include <iostream>
#include <map>
#define MAX 200001
using namespace std;
int Parent[MAX];
int countFriend[MAX];

int getParent(int num){
    if(num == Parent[num]) return num;
    return Parent[num] = getParent(Parent[num]);
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a != b) {
        if(a < b){
            Parent[b] = a;
            countFriend[a] += countFriend[b];
        }
        else{
            Parent[a] = b;
            countFriend[b] += countFriend[a];    
        }
    }
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
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        for(int i = 0; i < MAX; i++) {
            Parent[i] = i;
            countFriend[i] = 1;
        }
        map<string, int> index;
        string u, v;
        int num = 1;
        int a, b;
        for(int i = 0; i < N; i++){
            cin >> u >> v;
            if(index.count(u) == 0) index[u] = num++;
            a = index[u];
            if(index.count(v) == 0) index[v] = num++;
            b = index[v];
            unionParent(a, b);
            int root = getParent(a);
            cout << countFriend[root] << '\n';
        }
    }
}