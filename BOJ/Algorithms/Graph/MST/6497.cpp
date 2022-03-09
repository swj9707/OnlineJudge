#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200001
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
    while(1){
        int M, N; cin >> M >> N;
        if(N == 0 && M == 0) break;
        long long answer = 0;
        long long sum = 0;
        vector<pair<int, pair<int, int>>> edge(N);
        for(int i = 0; i < M; i++) Parent[i] = i;
        for(int i = 0; i < N; i++){
            int x, y, z; cin >> x >> y >> z;
            edge[i] = {z, {x, y}};
            sum += z;
        }
        sort(edge.begin(), edge.end());
        for(int i = 0; i < N; i++){
            int cost = edge[i].first;
            int src = edge[i].second.first;
            int dst = edge[i].second.second;
            if(!findParent(src, dst)){
                unionParent(src, dst);
                answer += cost;
            }
        }
        cout << sum - answer << '\n';
    }
}