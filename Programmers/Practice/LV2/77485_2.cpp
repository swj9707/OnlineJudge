#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define MAX 101
using namespace std;

int MATRIX[MAX][MAX];

void setMatrix(int rows, int columns){
    int index = 1;
    for(int y = 1; y <= rows; y++){
        for(int x = 1; x <= columns ; x++){
            MATRIX[y][x] = index;
            index++;
        }
    }
}

int rotate(int x1, int y1, int x2, int y2){
    int tmpData = MATRIX[y1][x1];
    int minData = tmpData;

    for(int i = y1 + 1; i <= y2; i++){
        MATRIX[i - 1][x1] = MATRIX[i][x1];
        minData = min(minData, MATRIX[i-1][x1]);
    }

    for(int i = x1; i < x2; i++){
        MATRIX[y2][i] = MATRIX[y2][i + 1];
        minData = min(minData, MATRIX[y2][i]);
    }

    for(int i = y2; i > y1; i--){
        MATRIX[i][x2] = MATRIX[i-1][x2];
        minData = min(minData, MATRIX[i][x2]);
    }
    for(int i = x2; i > x1; i--){
        MATRIX[y1][i] = MATRIX[y1][i-1];
        minData = min(minData, MATRIX[y1][i]);
    }
    MATRIX[y1][x1 + 1] = tmpData;
    return minData;
}


vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    setMatrix(rows, columns);
    for(auto i : queries){
        int x1, x2, y1, y2;
        x1 = i[1];
        y1 = i[0];
        x2 = i[3];
        y2 = i[2];
        answer.push_back(rotate(x1, y1, x2, y2));
    }

    return answer;
}