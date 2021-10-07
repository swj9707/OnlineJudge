#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#define MAX 500

using namespace std;

int matrix[MAX][MAX];
bool visit[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m, count, answer;

void initSet() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}

int BFS(int X, int Y){
    deque<pair<int, int>> q;
    q.push_back({X, Y});
    int area = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        visit[x][y] = true;
        area += 1;
        q.pop_front();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && matrix[nx][ny] == 1){
                visit[nx][ny] = true;
                q.push_back({nx, ny});
            }
        }
    }
    return area;
}

int main(){
    initSet();
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> matrix[i][j];
    }
    vector<int> data;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 1 && !visit[i][j]){
                int result = BFS(i, j);
                data.push_back(result);
            }
        }
    }
    if(!data.empty()){
        int max = *max_element(data.begin(), data.end());
        cout << data.size() << '\n';
        cout << max << '\n';
    }
    else cout << "0\n0\n";
}