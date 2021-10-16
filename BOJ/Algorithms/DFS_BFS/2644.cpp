#include <iostream>
#include <queue>
#define MAX 101

using namespace std;

int N;
int A, B;
int M;

int dist[MAX];
vector<int> V[MAX];

int BFS(int src, int dest){
    queue<int> Q;
    Q.push(src);
    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        if(x == dest) return dist[dest];
        unsigned long size = V[x].size();
        for(int i = 0; i < size; i++){
            int y = V[x][i];
            if(!dist[y]){
                Q.push(y);
                dist[y] = dist[x] + 1;
            }
        }
    }
    return -1;
}

int main(){
    cin >> N;
    cin >> A >> B;
    cin >> M;
    for(int T = 0; T < M; T++){
        int x,y;
        cin >> x >> y;
        V[x].push_back(y);
        V[y].push_back(x);
    }
    cout << BFS(A,B) << "\n";
}