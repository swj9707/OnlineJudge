#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001
using namespace std;

int N,M;
vector<pair<int, int>> edge[MAX];
bool visited[MAX];

int prim(){
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int result = 0;
    pq.push({0, 1});//시작은 0의 비용으로 1부터 시작
    for(int i = 1; i <= N; i++){
        while(!pq.empty() && visited[pq.top().second]){
            pq.pop();
        }//priority queue에 있는 데이터를 전부 꺼낸다. 단, visited 상에서 방문하고자 하는 곳이 true라면
        int next = pq.top().second;
        int minCost = pq.top().first;
        //priority queue의 top에 있는 값을 통해 다음 방문 노드, 최소 비용 갱신
        visited[next] = true;
        //다음 노드 방문처리하고
        result += minCost;
        //최소비용 결과에 더하고
        for(auto i : edge[next]){
            pq.push({i.second, i.first});
        }//이동하고자 하는 노드가 방문할 수 있는 모든곳을 priority queue에 저장
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int src, dst, cost;
        cin >> src >> dst >> cost;
        edge[src].push_back({dst, cost});
        edge[dst].push_back({src, cost});
    }

    cout << prim() << '\n';
}