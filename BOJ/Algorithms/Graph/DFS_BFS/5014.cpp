#include <iostream>
#include <deque>
#define MAX 1000001

using namespace std;

bool visit[MAX];

void BFS(int maxFloor, int now, int Dest, int up, int down){
    deque<pair<int, int>> DQ;
    DQ.push_back({now, 0});
    visit[now] = true;
    while(!DQ.empty()){
        int X = DQ.front().first;
        int count = DQ.front().second;
        DQ.pop_front();
        if(X == Dest){
            cout << count << "\n";
            return;
        }
        if(X + up <= maxFloor && !visit[X+up]){
            DQ.push_back({X+up, count + 1});
            visit[X+up] = true;   
        }
        if(X - down > 0 && !visit[X-down]){
            DQ.push_back({X-down, count + 1});
            visit[X-down] = true;   
        }
    }
    cout << "use the stairs" << '\n';
    return;
}

int main(){
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;
    BFS(F, S, G, U, D);
}