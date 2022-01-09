#include <iostream>
#include <algorithm>
#define MAX 9
using namespace std;

int N, M;
int MATRIX[MAX];
int DATA[MAX];
bool visit[MAX];

void DFS(int count){
    if(count == M){
        for(int i = 0; i < M; i++){
            cout << DATA[MATRIX[i]] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= N; i++){
        if(!visit[i]){//방문하지 않았다면
            visit[i] = true;//마커처리
            MATRIX[count] = i;//몇 번째 방문했는가?
            DFS(count + 1);//그 다음 count처리
            visit[i] = false;
            //저 위에 가득한 DFS들이 하나하나 return을 하기 시작하면 기존에 방문했던 놈들을 하나하나 false처리
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++) cin >> DATA[i];
    sort(DATA+1, DATA + N + 1);
    DFS(0);
}