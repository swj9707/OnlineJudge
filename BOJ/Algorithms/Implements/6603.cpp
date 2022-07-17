#include <bits/stdc++.h>

using namespace std;

int lotto[14];
int ans[6];

void DFS(int start, int depth, int K){
    if(depth == 6){
        for(int i = 0; i < 6; i++){
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i = start; i < K; i++){
        ans[depth] = lotto[i];
        DFS(i + 1, depth+1, K);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int K;
    while(true){
        cin >> K;
        if(K == 0) break;
        for(int i = 0; i < K; i++){
            cin >> lotto[i];
        }
        DFS(0, 0, K);
        cout << '\n';
    }
}