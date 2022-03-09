#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;
//Kruskal algorithms
/*
  1. 모든 간선들의 가중치를 오름차순으로 정렬한다.
  2. 가중치가 가장 작은 간선을 선택한다.
  3. 2에서 선택한 간선이 연결하려는 2개의 노드가 아직 서로 연결되지 않은 상태라면, 2개의 노드를 서로 연결한다.
  4. 위의 과정을 반복한다.
*/
int N, M;
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
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    int result = 0;
    vector<pair<int, pair<int, int>>> vec(M);
    for(int i = 0; i < M; i++){
        int src, dst, cost;
        cin >> src >> dst >> cost;
        vec[i] = {cost, {src, dst}};
    }
    for(int i = 1; i <= N; i++) Parent[i] = i;
    sort(vec.begin(), vec.end());
    for(int i = 0; i < M; i++){
        int cost = vec[i].first;
        int src = vec[i].second.first;
        int dst = vec[i].second.second;
        if(!findParent(src, dst)){
            result += cost;
            unionParent(src, dst);
        }
    }
    cout << result << '\n';
}