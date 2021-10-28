#include <iostream>
#include <string>
#include <deque>
#include <set>

using namespace std;

int MATRIX[5][5];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
set <string> result;

void BFS(int Y, int X){
    deque<pair<int, int>> DQ;
    DQ.push_back({Y, X});
    int count = 5;
    while(count > 5){
        
    }
}

int main(){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++) cin >> MATRIX[i][j];
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++) cin >> MATRIX[i][j];
    }
}