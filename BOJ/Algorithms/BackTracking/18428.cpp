#include <bits/stdc++.h>
#define MAX 7
using namespace std;

char MATRIX[MAX][MAX];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<pair<int, int>> teacher, idx;

bool check(int x, int y, int N){
    for(int i = 0; i < 4; i++){
        int nx = x;
        int ny = y;

        while(nx > 0 && nx <= N && ny > 0 && ny <= N){
            if(MATRIX[nx][ny] == 'O') break;
            if(MATRIX[nx][ny] == 'S') return false;
            nx += dx[i];
            ny += dy[i];
        }
    }
    return true;
}

void DFS(int count, int num, int N){
    if(count == 3){
        for(auto i : teacher){
            if(!check(i.first, i.second, N))
            return;
        }
        cout << "YES\n";
        exit(0);
    }
    for(int i = num; i < idx.size(); i++){
        MATRIX[idx[i].first][idx[i].second] = 'O';
        DFS(count + 1, i + 1, N);
        MATRIX[idx[i].first][idx[i].second] = 'X';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> MATRIX[i][j];
            if(MATRIX[i][j] == 'T'){
                teacher.push_back({i, j});
            } else if (MATRIX[i][j] == 'X'){
                idx.push_back({i, j});
            }
        }
    }

    DFS(0, 0, N);
    cout << "NO\n";
    return 0;
}