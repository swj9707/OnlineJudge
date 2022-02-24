#include <iostream>
#include <cmath>
#define MAX 21
using namespace std;

bool check[MAX];
int statData[MAX][MAX];
int N;
int answer = 98765432;

void DFS(int X, int Count){
    if(Count == N / 2){
        int start = 0, link = 0;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N ; j++){
                if(check[i] == true && check[j] == true) start += statData[i][j];
                if(check[i] == false && check[j] == false) link += statData[i][j];
            }
        }
        answer = min(answer, abs(start - link));
        return;
    }
    for(int i = X; i <= N; i++){
        check[i] = true;
        DFS(i+1, Count + 1);
        check[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++) cin >> statData[i][j];
    }
    DFS(1, 0);
    cout << answer << '\n';
}