#include <iostream>
#define MAX 9
using namespace std;

int N, M;
int MATRIX[MAX];
int DATA[MAX];
bool visit[MAX];

void DFS(int num, int count){
    if(count == M){
        for(int i = 0; i < M; i++){
            cout << MATRIX[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i = num; i <= N; i++){
        if(!visit[i]){
            visit[i] = true;
            MATRIX[count] = i;
            DFS(i+1, count + 1);
            visit[i] = false;
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++) cin >> DATA[i];
    DFS(1, 0);
}