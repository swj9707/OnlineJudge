#include <bits/stdc++.h>
#define MAX 9
using namespace std;

bool Visit[MAX];
int MATRIX[MAX];

void DFS(int count, int N){
    if(count == N){
        for(int i = 0; i < N; i++){
            cout << MATRIX[i] << " ";
        }
        cout << '\n';
    }
    for(int i = 1; i <= N; i++){
        if(!Visit[i]){
            Visit[i] = true;
            MATRIX[count] = i;
            DFS(count + 1, N);
            Visit[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    DFS(0, N);
}