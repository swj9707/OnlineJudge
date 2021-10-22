#include <iostream>
#include <queue> 
#define MAX 1000000 + 1

using namespace std;

bool visit[MAX];

void BFS(int maxFloor, int nowStair, int Dest, int Up, int Down){
    queue<pair<int, int>> DQ;
    DQ.push({nowStair, 0});
    visit[nowStair] = true;
    while(!DQ.empty()){
        int X = DQ.front().first;
        int count = DQ.front().second;
        DQ.pop();
        if(X == Dest){
            cout << count << "\n";
            return;
        }
        if(!visit[X + Up] && X + Up <= maxFloor) {
            DQ.push({X + Up, count + 1});
            visit[X + Up] = true;
        }  
        if(!visit[X - Down] && X - Down >= 1) {
            DQ.push({X - Down, count + 1});
            visit[X - Down] = true;
        }
    }
    cout << "use the stairs" << "\n";
    return;
}

int main(){
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;
    BFS(F, S, G, U, D);
}