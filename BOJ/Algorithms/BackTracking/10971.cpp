#include <bits/stdc++.h>
#define MAX 11
using namespace std;

int adj[MAX][MAX];
int MATRIX[MAX];
bool VISIT[MAX];

int minValue = 9999999999;

void DFS(int count, int N){
    if(count == N){
        int sumOfCost = 0;
        int check = 0;
        for(int i = 0; i < N - 1; i++){
            int cost = adj[MATRIX[i]][MATRIX[i+1]];
            if(cost == 0) check = 1;
            else sumOfCost += cost;
        }

        if(check == 0 && adj[MATRIX[N-1]][MATRIX[0]] != 0){
            sumOfCost += adj[MATRIX[N-1]][MATRIX[0]];
            minValue = min(minValue, sumOfCost);
        }
    
        return;
    }

    for(int i = 1; i <= N; i++){
        if(!VISIT[i]){
            VISIT[i] = true;
            MATRIX[count] = i;
            DFS(count + 1, N);
            VISIT[i] = false;
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int cost; 
            cin >> cost;
            adj[i][j] = cost;
        }
    }

    DFS(0, N);
    cout << minValue << '\n';
}