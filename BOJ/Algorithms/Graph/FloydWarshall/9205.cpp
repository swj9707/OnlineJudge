#include <iostream>
#include <vector>
#include <cstring>
#define MAX 103

using namespace std;

bool visit[MAX];
vector<int> adj[MAX];

void init(){
    memset(visit, false, sizeof(visit));
    for(int i = 0; i < MAX; i++) adj[i].clear();
}

void DFS(int X){
    visit[X] = true;
    for(auto i : adj[X]){
        if(!visit[i]) DFS(i);
    }
}

int getDist(pair<int, int> a, pair<int, int> b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TestCase;
    cin >> TestCase;
    for(int tc = 0; tc < TestCase; tc++){
        init();
        int N;
        cin >> N;
        vector<pair<int, int>> vec(N+2);
        for(auto & i : vec) cin >> i.first >> i.second;
        for(int i = 0; i < N+2; i++){
            for(int j = i + 1; j < N+2; j++){
                int dist = getDist(vec[i], vec[j]);
                if(dist <= 1000){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        DFS(0);
        if(visit[N+1]) cout << "happy\n";
        else cout << "sad\n";
    }
}