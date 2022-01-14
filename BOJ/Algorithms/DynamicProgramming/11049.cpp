#include <iostream>
#define MAX 501
#define INF 987654321
using namespace std;

int DP[MAX][MAX];
int MATRIX[MAX][2];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> MATRIX[i][0] >> MATRIX[i][1];
    }
}