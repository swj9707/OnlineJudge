#include <iostream>
#define MAX 101
using namespace std;
int N, M, K;
int Matrix[MAX][MAX];
bool visit[MAX];

int main(){
    cin >> N >> M >> K;
    for(int i = 0; i < K; i++){
        int r, c;
        cin >> r >> c;
        Matrix[r][c] = 1;
        Matrix[c][r] = 1;
    }
    
}