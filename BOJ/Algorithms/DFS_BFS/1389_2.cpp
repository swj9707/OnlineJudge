#include <iostream>
#include <queue>
#include <cstring>
#define MAX 101
using namespace std;

int N, M;
int MATRIX[MAX][MAX];
bool VISIT[MAX];
int connect[MAX];
int resultBFS[MAX];
void BFS(int a){
    queue<int> Q;
    Q.push(a);
    VISIT[a] = true;
    while(!Q.empty()){
        int x = Q.front();
        Q.pop();
        for(int i = 1; i <= N; i++){
            if(MATRIX[x][i] != 0 && !VISIT[i]){
                VISIT[i] = true;
                Q.push(i);
                connect[i] += 1;
            }
        }
    }
} 

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        MATRIX[a][b] = 1;
        MATRIX[b][a] = 1;
    }
    for(int i = 1; i <= N; i++){
        BFS(i);
        for(int j = 1; j <= N; j++){
            resultBFS[i] = resultBFS[j] + connect[j];
        }
        memset(VISIT, false, sizeof(VISIT));
        memset(connect, 0, sizeof(connect));
    }
    int min = resultBFS[1];
    int answer = 1;
    for(int i = 2; i <= N; i++){
        if(min > resultBFS[i]){
            min = resultBFS[i];
            answer = i;
        }
    }
    cout << answer << '\n';
}