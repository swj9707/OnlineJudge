#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

int Parent[MAX];

int getParent(int X){
    if(X == Parent[X]) return X;
    return Parent[X] = getParent(Parent[X]);
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
    long long answer = 0;
    int N; cin >> N;
    vector<pair<long long, pair<int, int>>> edge;
    for(int i = 0; i <= N; i++) Parent[i] = i;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            long long cost; cin >> cost;
            if(i != j){
                edge.push_back({cost, {i, j}});
            }
        }
    }
    sort(edge.begin(), edge.end());
    for(int i = 0; i < edge.size(); i++){
        long long cost = edge[i].first;
        int src = edge[i].second.first;
        int dst = edge[i].second.second;
        if(!findParent(src, dst)){
            unionParent(src, dst);
            answer += cost;
        }
    }
    cout << answer << '\n';
}