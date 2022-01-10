#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 32001
using namespace std;

int indegree[MAX];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;//사람 수, 키를 비교한 순서
    
    vector<int> v[MAX];
    queue<int> q;
    vector<int> answer;

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;//키를 비교한 두 학생 번호
        cin >> a >> b;
        v[a].push_back(b);//a 뒤에 b가 줄을 섰다는 의미
        indegree[b]++;//b에 대한 간선의 수 증가
    }

    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            answer.push_back(i);
            q.push(i);
        }//하나 하나 뒤져보면서 간선의 수가 없다면 answer에 저장 및 queue에 저장
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();//queue에 데이터를 하나 씩 뽑아가면서
        for (int i = 0; i < v[x].size(); i++) {//해당 노드 뒤에있는 노드 갯수만큼 반복
            indegree[v[x].at(i)]--;//해당 노드에 연결되어있는 놈의 간선을 감소시키고
            if (indegree[v[x].at(i)] == 0) {//만약 간선이 0이라면
                q.push(v[x].at(i));
                answer.push_back(v[x].at(i));
                //queue에 집어넣고 answer에 저장
            }
       }
    }
    for(auto i : answer) cout << i << '\n';
    return 0;
}