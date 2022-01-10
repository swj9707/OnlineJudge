#include <iostream>
#include <queue>
#include <vector>
#define MAX 32001
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> node[MAX];
    vector<int> answer;
    int indegree[MAX] = {0};
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;
        node[A].push_back(B);
        indegree[B]++;
    }
    for(int i = 1; i <= N; i++) if(!indegree[i]) pq.push(i);
    while(!pq.empty()){
        int X = pq.top();
        pq.pop();
        answer.push_back(X);
        for(auto next : node[X]){
            if(--indegree[next] == 0) pq.push(next);
        }
    }
    for(auto i : answer) cout << i << " ";
}