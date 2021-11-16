#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> Vec[50001];
int node[20001];
int maxLength;
bool comp(int a, int b){
    return a > b;
}

void BFS(){
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int current = q.front();
        q.pop();
        for(int i = 0; i < Vec[current].size(); i++){
            if(node[Vec[current][i]] == 0 && Vec[current][i] != 1){
                node[Vec[current][i]] = node[current] + 1;
                q.push(Vec[current][i]);
                maxLength = max(maxLength, node[Vec[current][i]]);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge){
    int answer = 0;
    for(int i = 0; i < edge.size(); i++){
        Vec[edge[i][0]].push_back(edge[i][1]);
        Vec[edge[i][1]].push_back(edge[i][0]);
    }
    for(int i = 1; i <= n; i++){
        if(maxLength == node[i]) answer++;
    }
    return answer;
}

int main(){

}