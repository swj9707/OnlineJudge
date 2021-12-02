#include <iostream>
#include <deque>
using namespace std;

int N, M;
int matrix[501][501];
bool visit[501];

int BFS(){
    int X = 1;
    int answer = 0;
    deque<pair<int, int>> dq;
    visit[X] = 1;
    dq.push_back({X, 0});
    while(!dq.empty()){
        int x = dq.front().first;
        int depth = dq.front().second;
        dq.pop_front();
        if(depth <= 2) answer++;
        for(int i = 1; i <= N; i++){
            if(matrix[x][i] && !visit[i]){
                visit[i] = 1;
                dq.push_back({i, depth+1});
            }
        }
    }
    return answer - 1;
}

int main(){
    cin >> N;
    cin >> M;
    for(int i = 0; i < M; i++){
        int x, y;
        cin >> x >> y;
        matrix[x][y] = matrix[y][x] = 1;
    }
    int answer = BFS();
    cout << answer << '\n';
}