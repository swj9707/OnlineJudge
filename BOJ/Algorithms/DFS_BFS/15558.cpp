#include<iostream>
#include<deque>
#include<tuple>
#include <cstring>
 
using namespace std;
 
int map[2][200000];
bool Visit[2][200000];
int n, k;

void init(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void BFS(){
    deque < tuple<int, int, int>>q;
    q.push_back({ 0,0,0 });
  
    Visit[0][0] = true;
    while (!q.empty()) {
        int line, x, sec;
        tie(line, x, sec) = q.front();
        Visit[line][x] = true;
        q.pop_front();
        if (x >= n) {
            cout << 1 << '\n';
            return;
        }
        if (map[line][x + 1] != 0 && !Visit[line][x+1]) {
            q.push_back({ line, x + 1, sec + 1 });     
            Visit[line][x+1] = true;
        }
        if (x - 1 > sec && map[line][x - 1] != 0 && !Visit[line][x - 1]) {
            q.push_back({ line, x - 1, sec + 1 });
            Visit[line][x-1] = true;
        }
        if (line == 0) {
            if (map[1][x + k] != 0 && !Visit[1][x + k]) {
                q.push_back({ 1, x + k, sec + 1 });
                Visit[1][x+k] = true;
            }
        }
        if (line == 1) {
            if (map[0][x + k] != 0 && !Visit[0][x + k]) {
                q.push_back({ 0, x + k, sec + 1 });
                Visit[0][x+k] = true;
            }
            }
        }
    cout << "0\n";
    return;
}

int main() {
    init();
    cin >> n >> k;
    memset(map, 1, sizeof(map));
    for (int i = 0; i < 2; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < n; j++) {
            map[i][j] = tmp[j] - '0';
        }
    }
    BFS();
    return 0;
}
