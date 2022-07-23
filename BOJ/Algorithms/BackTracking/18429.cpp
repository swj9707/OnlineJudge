#include <bits/stdc++.h>
#define MAX 9
using namespace std;

bool VISIT[MAX];
int MATRIX[MAX];
int DATA[MAX];
int answer;
void DFS(int count, int N, int K){
    if(count == N){
        int amount = 500;
        for(int i = 0; i < N; i++){
            amount += DATA[MATRIX[i]];
            amount -= K;
            if(amount < 500) return;
        }
        answer++;
        return;
    }
    for(int i = 1; i <= N; i++){
        if(!VISIT[i]){
            VISIT[i] = true;
            MATRIX[count] = i;
            DFS(count+1, N, K);
            VISIT[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    for(int i = 1; i <= N; i++) cin >> DATA[i];
    DFS(0, N, K);
    cout << answer << '\n';
}