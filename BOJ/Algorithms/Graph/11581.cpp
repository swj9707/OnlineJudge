#include <bits/stdc++.h>
#define MAX 101
using namespace std;

vector<int> vec[MAX];
int visited[MAX];

bool DFS(int start){
    if(visited[start]){
        if(visited[start] == -1) return true;
        return false;
    }
    visited[start] = -1;
    for(int i = 0; i < vec[start].size(); i++){
        int next = vec[start][i];
        if(DFS(next)) return true;
    }
    visited[start] = 1;
    return false;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for(int i = 1; i <= N-1; i++){
        int cnt; cin >> cnt;
        for(int j = 0; j < cnt; j++){
            int input; cin >> input;
            vec[i].push_back(input);
        }
    }
    if(DFS(1)){
        cout << "CYCLE\n";
    } else {
        cout << "NO CYCLE\n";
    }
}