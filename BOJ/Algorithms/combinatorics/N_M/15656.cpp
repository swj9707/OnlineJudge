#include <iostream>
#include <algorithm>
#define MAX 8
using namespace std;

int N, M;
int MATRIX[MAX];
bool visit[MAX];
int DATA[MAX];
void DFS(int count){
    if(count == M){
        for(int i = 0; i < M; i++){
            cout << DATA[MATRIX[i]] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= N; i++){
        visit[i] = true;
        MATRIX[count] = i;
        DFS(count + 1);
        visit[i] = false;
    }
}

int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++) cin >> DATA[i];
    sort(DATA+1, DATA+1+N);
    DFS(0);
}