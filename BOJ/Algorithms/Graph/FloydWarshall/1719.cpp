#include <iostream>
#define MAX 201
#define INF 9999
using namespace std;

int edge[MAX][MAX];
int MATRIX[MAX][MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M; cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(i != j) edge[i][j] = INF;
        }
    }
    for(int i = 0; i < M; i++){
        int src, dst, cost; cin >> src >> dst >> cost;
        edge[src][dst] = edge[dst][src] = cost;
        MATRIX[src][dst] = dst;
        MATRIX[dst][src] = src;
    }
    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(edge[i][j] > edge[i][k] + edge[k][j]){
                    edge[i][j] = edge[i][k] + edge[k][j];
                    MATRIX[i][j] = MATRIX[i][k];
                }
            }
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(i == j) cout <<"- ";
            else cout << MATRIX[i][j] << " ";
        }
        cout << '\n';
    }
}