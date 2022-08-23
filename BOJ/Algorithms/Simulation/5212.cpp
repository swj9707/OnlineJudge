#include <bits/stdc++.h>
#define MAX 12
using namespace std;

char MATRIX[MAX][MAX];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void initSetup(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            MATRIX[i][j] = '.';
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    initSetup();

    int R, C;
    vector<pair<int, int>> vec;
    cin >> R >> C;
    for(int r = 1; r <= R; r++){
        for(int c = 1; c <= C; c++){
            cin >> MATRIX[r][c];
        }
    }

    for(int r = 1; r <= R; r++){
        for(int c = 1; c <= C; c++){
            if(MATRIX[r][c] == 'X'){
                int count = 0;
                for(int i = 0; i < 4; i++){
                    int nr = dx[i] + r;
                    int nc = dy[i] + c;
                    if(MATRIX[nr][nc] == '.'){
                        count++;
                    }
                }
                if(count >= 3){
                    vec.push_back({r, c});
                }
            }
        }
    }

    for(int i = 0; i < vec.size(); i++){
        MATRIX[vec[i].first][vec[i].second] = '.';
    }

    int minRow = 11, maxRow = 0, minCol = 11, maxCol = 0;

    for(int r = 1; r <= R; r++){
        for(int c = 1 ; c <= C; c++){
            if(MATRIX[r][c] == 'X'){
                minRow = min(minRow, r);
                maxRow = max(maxRow, r);
                minCol = min(minCol, c);
                maxCol = max(maxCol, c);
            }
        }
    }

    for(int r = minRow ; r <= maxRow; r++){
        for(int c = minCol; c <= maxCol; c++){
            cout << MATRIX[r][c];
        }
        cout << '\n';
    }
}