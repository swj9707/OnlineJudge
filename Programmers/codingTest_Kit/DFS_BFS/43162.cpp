#include <string>
#include <vector>
#define MAX 201
using namespace std;

bool Visit[MAX];
vector<int> vec[MAX];

void DFS(int X){
    for(int i = 0; i < vec[X].size(); i++){
        int node = vec[X][i];
        if(!Visit[node]){
            Visit[node] = true;
            DFS(node);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0; i < computers.size(); i++){
        for(int j = 0; j < n; j++){
            if(i != j){
                if(computers[i][j] == 1){
                    vec[i].push_back(j);
                }
            }
        }
    }

    for(int i = 0; i < n ; i++){
        if(!Visit[i]) {
            DFS(i);
            answer++;
        }
    }
    return answer;
}