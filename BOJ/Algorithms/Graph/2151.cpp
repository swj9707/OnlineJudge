#include <iostream>
#include <vector>
#include <queue>
#define MAX 51
#define INF 98765432
using namespace std;

char MAP[MAX][MAX];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0 ,0};
int Dist[MAX][MAX][4];

void Dijkstra(){

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == '#')
        }
    }
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){

        }
    }
}