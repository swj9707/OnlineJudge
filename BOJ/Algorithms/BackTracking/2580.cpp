#include <iostream>
#include <vector>

using namespace std;

int MATRIX[9][9];
vector<pair<int, int>> PointVec;
bool found = false;
bool check(pair<int, int> p){
    int xSquare = p.first / 3;
    int ySquare = p.second / 3;
    for(int i = 0; i < 9; i++){
        if(MATRIX[p.first][i] == MATRIX[p.first][p.second] && i != p.second) return false;
        if(MATRIX[i][p.second] == MATRIX[p.first][p.second] && i != p.first) return false;
        for(int i = 3 * xSquare ; i < 3 * xSquare + 3; i++){
            for(int j = 3 * ySquare; j < 3 * ySquare + 3; j++){
                if(MATRIX[i][j] == MATRIX[p.first][p.second]){
                    if(i != p.first && j != p.second) return false;
                }
            }
        }
        return true;
    }
}

void sudoku(int N, int cnt){
 if(N == cnt)
    {
        for(int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << MATRIX[i][j] << ' ';
            cout << '\n';
        } 
        found = true;
        return;
    }
        for(int j = 1; j <= 9; j++)
        {
            MATRIX[PointVec[N].first][PointVec[N].second] = j;
            if(check(PointVec[N])) 
                sudoku(N+1, cnt);
            if(found) 
                return;
        }
    MATRIX[PointVec[N].first][PointVec[N].second] = 0;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++) {
            cin >> MATRIX[i][j];
            if(MATRIX[i][j] == 0) {
                PointVec.push_back({i, j});
            }
        }
    }
    int count = PointVec.size();
    sudoku(0, count);
}