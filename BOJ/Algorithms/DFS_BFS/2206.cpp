#include <iostream>
#include <deque>
#define MAX 1001

using namespace std;

int N, M;
int MATRIX[MAX][MAX];
bool visit[MAX][MAX];

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) cin >> MATRIX[i][j];
    }

}