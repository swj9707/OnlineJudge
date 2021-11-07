#include<iostream>
#include<queue>
#include<tuple>
 
using namespace std;
 
int map[2][200000];
bool Visit[2][200000];
int n, k;

void BFS(){
    queue < tuple<int, int, int>>q;
    q.push({ 0,0,0 });
    Visit[0][0] = true;
 
    while (!q.empty()) {
        int line, x, sec;
        tie(line, x, sec) = q.front();
        q.pop();
        if (x >= n) {
            cout << 1 << '\n';
            return;
        }
        if (map[line][x+1] != 0 && !Visit[line][x+1]) {
            Visit[line][x + 1] = true;
            q.push({ line,x + 1,sec + 1 });
        }
        if (x - 1 > sec && map[line][x-1] != 0 && !Visit[line][x-1]) {
            Visit[line][x - 1] = true;
            q.push({ line,x - 1,sec + 1 });
        }
        if (line == 0) {
            if (map[1][x+k] != 0 && !Visit[1][x+k]) {
                Visit[1][x + k] = true;
                q.push({ 1,x + k,sec + 1 });
            }
        }
        if (line == 1) {
            if (map[0][x+k] != 0 && !Visit[0][x+k]) {
                Visit[0][x + k] = true;
                q.push({ 0,x + k,sec + 1 });
            }
        }
    }
    cout << "0\n";
} 

int main() {
    cin >> n >> k;
 
    for (int i = 0; i < 2; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < n; j++) {
            if(tmp[j] == '0') map[i][j] = 0;
            else map[i][j] = 1;
        }
    }
    BFS();
    return 0;
}
