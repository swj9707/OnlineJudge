#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
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
    int N, M; cin >> N >> M;
    long long answer = 0;
    int Max = 0;
    vector<pair<int, pair<int, int>>> edge(M);
    for(int i = 0; i < M; i++){
        int src, dst, cost;
        cin >> src >> dst >> cost;
        edge[i] = {cost, {src, dst}};
    }
    for(int i = 0; i <= N; i++) Parent[i] = i;
    sort(edge.begin(), edge.end());
    for(int i = 0; i < M; i++){
        int cost = edge[i].first;
        int src = edge[i].second.first;
        int dst = edge[i].second.second;
        if(!findParent(src, dst)){
            unionParent(src, dst);
            answer += cost;
            Max = max(Max, cost);
        }
    }
    cout << answer - Max << '\n';
}
