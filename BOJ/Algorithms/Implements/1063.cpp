#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int kingIndex_X, kingIndex_Y;
int stoneIndex_X, stoneIndex_Y;

enum Index {R, L, B, T, RT, LT, RB, LB};
int dx[8] = {1, -1,  0,  0, 1,-1, 1,-1};
int dy[8] = {0,  0, -1,  1, 1, 1,-1,-1};

queue<string> Q;

int check(string X){
    if (X == "R") return R;
    else if (X == "L") return L;
    else if (X == "B") return B;
    else if (X == "T") return T;
    else if (X == "RT") return RT;
    else if (X == "LT") return LT;
    else if (X == "RB") return RB;
    else if (X == "LB") return LB;
    return -1;
}

void Search(){
    while(!Q.empty()){
        string move = Q.front();
        int index = check(move);
        Q.pop();
        int k_X = kingIndex_X + dx[index];
        int k_Y = kingIndex_Y + dy[index];
        int s_X = stoneIndex_X;
        int s_Y = stoneIndex_Y;
        if(stoneIndex_X == k_X && stoneIndex_Y == k_Y){
            s_X = stoneIndex_X + dx[index];
            s_Y = stoneIndex_Y + dy[index];
        }
        if(k_X > 0 && k_X < 9 && k_Y > 0 && k_Y < 9 && s_X > 0 && s_X < 9 && s_Y > 0 && s_Y < 9){
            kingIndex_X = k_X; kingIndex_Y = k_Y;
            stoneIndex_X = s_X; stoneIndex_Y = s_Y;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string kingIndex, stoneIndex;
    int N;
    cin >> kingIndex >> stoneIndex >> N;
    kingIndex_X = kingIndex[0] - 64, kingIndex_Y = kingIndex[1] - 48;
    stoneIndex_X = stoneIndex[0] - 64, stoneIndex_Y = stoneIndex[1] - 48;
    for(int i = 0; i < N; i++){
        string tmp;
        cin >> tmp;
        Q.push(tmp);
    }
    Search();
    cout << (char)(kingIndex_X + 64) << kingIndex_Y << '\n';
    cout << (char)(stoneIndex_X + 64) << stoneIndex_Y << '\n';
}