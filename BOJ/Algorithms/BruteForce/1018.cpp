#include <iostream>
#include <string>

using namespace std;

int N, M;
string MATRIX[50];
string WB[8]{
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};
string BW[8]{
    "BWBWBWBW",
    "WBWBWBWB", 
    "BWBWBWBW",
    "WBWBWBWB", 
    "BWBWBWBW",
    "WBWBWBWB", 
    "BWBWBWBW",
    "WBWBWBWB",
};
int WBCount(int x, int y){
    int count = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(MATRIX[x+i][y+j] != WB[i][j]) count += 1;
        }
    }
    return count;
}
int BWCount(int x, int y){
    int count = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(MATRIX[x+i][y+j] != BW[i][j]) count += 1;
        }
    }
    return count;
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> MATRIX[i];
    }
    int minimum = 99999;
    for(int i = 0; i + 8 <= N; i++){
        for(int j = 0; j + 8 <= M; j++){
            int tmp;
            tmp = min(WBCount(i, j), BWCount(i, j));
            if (tmp < minimum) minimum = tmp;
        }
    }
    cout << minimum << '\n';
    return 0;
}