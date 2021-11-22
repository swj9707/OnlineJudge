#include <iostream>
#define DICE 6
#define MAX 21

using namespace std;

int N, M, initx, inity, K;
//이동 방향 : 동 1 서 2 북 3 남 4
int MATRIX[MAX][MAX];
int dice[DICE] = {}

int roll(int movepoint){
    return 0;
}

int main(){
    cin >> N >> M >> initx >> inity >> K;
    //가로 세로 크기, 주사위를 놓은 곳, 명령의 갯수
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) cin >> MATRIX[i][j];
    }
    int movepoint;
    for(int i = 0; i < K; i++){
        cin >> movepoint;
    }
}