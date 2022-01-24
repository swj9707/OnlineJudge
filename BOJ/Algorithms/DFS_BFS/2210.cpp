#include <iostream>
#include <string>
#include <deque>
#include <set>

using namespace std;

int MATRIX[6][6];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
set <string> result;

void BFS(int X, int Y){
    deque<pair<string, pair<int, int>>> DQ;
    DQ.push_back({to_string(MATRIX[X][Y]), {X, Y}});
    while(!DQ.empty()){
        string data = DQ.front().first;
        int x = DQ.front().second.first;
        int y = DQ.front().second.second;
        if(data.length() == 6)
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
        }
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++) cin >> MATRIX[i][j];
    }

}