#include <iostream>
#include <queue>
#include <vector>
#define MAX 501
using namespace std;

int indegree[MAX];
int cost[MAX];
int answer[MAX];
vector<int> v[MAX];
queue<int> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    for(int i = 1; i <= N; i++){
        int tmp;
        cin >> tmp;
        cost[i] = tmp;
        while(1){
            cin >> tmp;
            if(tmp == -1) break;
            v[tmp].push_back(i);
            indegree[i]++;
        }
    }
    for(int i = 1; i <= N; i++){
        if(indegree[i] == 0){
            q.push(i);
            answer[i] = cost[i];
        }
    }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i = 0; i < v[x].size(); i++){
            int next = v[x].at(i);
            indegree[next]--;
            answer[next] = max(answer[next], answer[x] + cost[next]);
            if(indegree[next] == 0){
                q.push(next);
            }
        }
    }
    for(int i = 1; i <= N; i++) cout << answer[i] << '\n';
    return 0;
}