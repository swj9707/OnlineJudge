#include <iostream>
#include <deque>
using namespace std;

int N;
int Arr[1001];
bool visit[1001];
void BFS(){
    deque<pair<int, int>> dq;
    dq.push_back({0, 1});
    visit[1] = true;
    while(!dq.empty()){
        int count = dq.front().first;
        int X = dq.front().second;
        if(X == N){
            cout << count + 1 << '\n';
            return;
        }
        dq.pop_front();
        if(Arr[X] != 0){
            for(int i = 1; i <= Arr[X]; i++){
                int nx = X + i;
                if(nx >= 1 && nx <= N && !visit[nx]){
                    visit[nx] = true;
                    dq.push_back({count++, nx});
                }
            }
        }
    }
    cout << "-1\n";
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> Arr[i];
    BFS();
    return 0;
}