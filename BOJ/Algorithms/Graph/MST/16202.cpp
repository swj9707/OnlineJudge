#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

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
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M, K; cin >> N >> M >> K;
    int idx = 0;
    vector<pair<int, pair<int, int>>> edge;
    for(int i = 1; i <= M; i++){
        int src, dst; cin >> src >> dst;
        edge.push_back({i, {src, dst}});
    }
    bool check = false;
    while(K--){
        if(check){
            cout << "0 ";
            continue;
        }
        int count = 0, answer = 0;
        for(int i = 0; i <= N; i++) Parent[i] = i;
        for(int i = idx; i < edge.size(); i++){
            int cost = edge[i].first;
            int src = edge[i].second.first;
            int dst = edge[i].second.second;
            if(!findParent(src, dst)){
                unionParent(src, dst);
                answer += cost;
                count++;
            }
        }
        if(count == N - 1) cout << answer << " ";
        else {
            check = true;
            cout << "0 ";
        }
        idx++;
    }
}