#include <iostream>
#define MAX 8
using namespace std;

int N, M;
int MATRIX[MAX];
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
        visit[i] = true;
        MATRIX[count] = i;
        DFS(i, count + 1);
        visit[i] = false;
    }
}

int main(){
    cin >> N >> M;
    DFS(1, 0);
}