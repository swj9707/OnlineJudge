#include <iostream>
#define MAX 8
using namespace std;

int N, M;
int MATRIX[MAX];
bool visit[MAX];

void DFS(int count){
    if(count == M){
        for(int i = 0; i < M; i++){
            cout << MATRIX[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= N; i++){
        if(!visit[i]){
            visit[i] = true;
            MATRIX[count] = i;
            DFS(count + 1);
            visit[i] = false;
        }
    }
}

int main(){
    cin >> N >> M;
    DFS(0);
}