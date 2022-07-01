#include <bits/stdc++.h>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    while(T--){
        int X = 0, Y = 0;
        int dir = 0;
        int maxX = 0, maxY = 0, minX = 0, minY = 0;
        string cmd; cin >> cmd;
        for(auto i : cmd){
            if(i == 'F'){
                X += dx[dir];
                Y += dy[dir];
            }else if (i == 'B'){
                X -= dx[dir];
                Y -= dy[dir];
            }else if (i == 'L'){
                if(dir < 3) dir++;
                else dir = 0;
            }else if (i == 'R'){
                if(dir > 0) dir--;
                else dir = 3;
            }
            maxX = max(maxX, X);
            maxY = max(maxY, Y);
            minX = min(minX, X);
            minY = min(minY, Y);
        }
        int width = maxX - minX;
        int height = maxY - minY;
        cout << width * height << '\n';
    }
}