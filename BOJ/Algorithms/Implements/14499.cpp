#include <iostream>
#define DICE 6
#define MAX 21

using namespace std;

int N, M, initx, inity, K;
//이동 방향 : 동 1 서 2 북 3 남 4
int MATRIX[MAX][MAX];
int movePointList[1001];
int dice[DICE] = {0,};
int dice_index[DICE] = {1,5,3,2,4,6};


void dice_ChgIndex(int movepoint){
    int sub = dice_index[0];
    if(movepoint == 1){
        dice_index[0] = dice_index[4];
        dice_index[4] = dice_index[5];
        dice_index[5] = dice_index[2];
        dice_index[2] = sub;
    }
    else if(movepoint == 2){
        dice_index[0] = dice_index[2];
        dice_index[2] = dice_index[5];
        dice_index[5] = dice_index[4];
        dice_index[4] = sub;
    }
    else if(movepoint == 3){
        dice_index[0] = dice_index[1];
        dice_index[1] = dice_index[5];
        dice_index[5] = dice_index[3];
        dice_index[3] = sub;
    }
    else if(movepoint == 4){
        dice_index[0] = dice_index[3];
        dice_index[3] = dice_index[5];
        dice_index[5] = dice_index[1];
        dice_index[1] = sub;
    }
    else cout << "error!!\n";
}

int chgDicePosition(int movepoint){
    if(movepoint == 1){
        if(initx + 1 < M){
            initx += 1;
            return 1;
        }
    }
    else if(movepoint == 2){
        if(initx - 1 >= 0){
            initx -= 1;
            return 1;
        }
    }
    else if(movepoint == 3){
        if(inity - 1 >= 0){
            inity -= 1;
            return 1;
        }
    }
    else if(movepoint == 4){
        if(inity + 1 < N){
            inity += 1;
            return 1;
        }
    }
    return 0;
}

int main(){
    cin >> N >> M >> initx >> inity >> K;
    //가로 세로 크기, 주사위를 놓은 곳, 명령의 갯수
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) cin >> MATRIX[i][j];
    }
    for(int i = 1; i <= K; i++) cin >> movePointList[i];
    for(int i = 1; i <= K; i++){
        if(chgDicePosition(i) == 1){

        }
    }
}