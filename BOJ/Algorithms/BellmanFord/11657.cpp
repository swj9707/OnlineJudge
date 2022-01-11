#include <iostream>
#define MAX 501
#define INF 99999
using namespace std;
int N, M;
int MATRIX[MAX][MAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++) MATRIX[i][j] = INF;
    }
    for(int i = 0; i < M; i++){
        int A, B, C;
        cin >> A >> B >> C;
        
    }
}