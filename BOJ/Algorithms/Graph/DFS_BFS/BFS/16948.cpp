#include <bits/stdc++.h>

using namespace std;

int dr[6] = {-2, -2, 0, 0, 2, 2};
int dc[6] = {-1, 1, -2, 2, -1, 1};
bool VISIT[201][201];

void BFS(int srcR, int srcC, int dstR, int dstC, int N){
    queue<pair<pair<int, int>, int>> Q;
    Q.push({{srcR, srcC}, 0});
    VISIT[srcR][srcC] = true;
    while(!Q.empty()){
        int R = Q.front().first.first;
        int C = Q.front().first.second;
        int count = Q.front().second;
        if(R == dstR && C == dstC){
            cout << count << '\n';
            return;
        }
        Q.pop();
        for(int i = 0; i < 6; i++){
            int nr = R + dr[i];
            int nc = C + dc[i];
            if(nr >= 0 && nr < N && nc >= 0 && nc < N && !VISIT[nr][nc]){
                VISIT[nr][nc] = true;
                Q.push({{nr, nc}, count + 1});
            }
        }
    }
    cout << "-1\n";
    return;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    int srcR, srcC, dstR, dstC;
    cin >> srcR >> srcC >> dstR >> dstC;
    BFS(srcR, srcC, dstR, dstC, N);
}