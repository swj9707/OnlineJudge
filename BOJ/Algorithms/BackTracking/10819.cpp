#include <bits/stdc++.h>
#define MAX 9
using namespace std;

int MATRIX[MAX];
int DATA[MAX];
bool Visit[MAX];
int answer = -99;

void DFS(int count, int N){
    if(count == N){
        int sum = 0;
        for(int i = 0; i < N-1; i++){
            sum += abs(DATA[MATRIX[i]] - DATA[MATRIX[i+1]]);
        }
        answer = max(answer, sum);
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
    for(int i = 1; i <= N ;i++){
        cin >> DATA[i];
    }

    DFS(0, N);

    cout <<answer << '\n';

}