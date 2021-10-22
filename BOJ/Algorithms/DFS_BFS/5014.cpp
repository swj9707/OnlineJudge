#include <iostream>
#include <deque> 
#define MAX 1000001

using namespace std;

int Path[MAX];
bool visit[MAX];

int BFS(int maxFloor, int nowStair, int Dest, int Up, int Down){
    deque<pair<int, int>> DQ;
    int answer = -1;
    DQ.push_back({nowStair, 0});
    visit[nowStair] = true;
    while(!DQ.empty()){
        int X = DQ.front().first;
        int count = DQ.front().second;
        DQ.pop_front();
        if(X == maxFloor){
            answer = count;
            break;
        }
        if(!visit[X + Up] && X + Up <= maxFloor) {
            DQ.push_back({X+Up, count + 1});
            visit[X + Up] = true;
        }  
        if(!visit[X - Down] && X - Down > maxFloor) {
            DQ.push_back({X - Down, count + 1});
            visit[X - Down] = true;
        }
    }
    return answer;
}

int main(){
    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;
    int Answer = BFS(F, S, G, U, D);
    if(Answer != -1) cout << Answer << '\n';
    else cout << "use the stairs" << '\n';
}