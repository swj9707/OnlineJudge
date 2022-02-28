#include <iostream>

using namespace std;

int MATRIX[128][128];
int blue, white;

void check(int X, int Y, int size){
    bool BlueCheck = true, WhiteCheck = true;
    for(int i = X; i < X + size; i++){
        for(int j = Y; j < Y + size; j++){
            if(MATRIX[i][j] == 0) WhiteCheck = false;
            if(MATRIX[i][j] == 1) BlueCheck = false;
        }
    }
    if(BlueCheck == true){
        blue++;
        return;
    }
    if(WhiteCheck == true){
        white++;
        return;
    }
    check(X, Y, size / 2);
    check(X + size / 2, Y, size / 2);
    check(X, Y + size / 2, size / 2);
    check(X + size / 2, Y + size / 2, size / 2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> MATRIX[i][j];
    }
    check(0, 0, N);
    cout << blue << '\n';
    cout << white << '\n';
}