#include <bits/stdc++.h>
#define MAX 20001
using namespace std;

vector<int> adj[MAX];
int VISIT[MAX];

void BFS(){
    queue<int> que;
    VISIT[1] = 1;
    que.push(1);
    while(!que.empty()){
        int X = que.front();
        que.pop();
        for(int i = 0; i < adj[X].size(); i++){
            int dst = adj[X][i];
            if(!VISIT[dst]){
                que.push(dst);
                VISIT[dst] = VISIT[X] + 1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int src, dst;
        cin >> src >> dst;
        adj[src].push_back(dst);
        adj[dst].push_back(src);
    }

    BFS();
    int maxIdx = 0, maxNum = 0, maxCount = 1;
    for(int i = 2; i <= N; i++){
        if(VISIT[i] > maxNum){
            maxNum = VISIT[i];
            maxIdx = i;
            maxCount = 1;
        } else if (VISIT[i] == maxNum){
            maxCount++;
        }
    }

    cout << maxIdx << " " << maxNum - 1 << " " << maxCount << '\n';
}