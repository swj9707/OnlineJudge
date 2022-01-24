#include <iostream>
#include <cstring>
#define MAX 101

using namespace std;

int N;
int MATRIX[MAX][MAX];
bool visit[MAX];

void DFS(int x){
    for(int i = 0; i < N; i++){
        if(!visit[MATRIX[x][i]] && MATRIX[x][i] == 1){
            visit[MATRIX[x][i]] == true;
            DFS(MATRIX[x][i]);
        }
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> MATRIX[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        memset(visit, false, sizeof(visit));
        DFS(i);
        for(int j = 0; j < N; j++){
            cout << visit[j] << " ";
        }
        cout << "\n";
    }
}