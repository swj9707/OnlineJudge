#include <iostream>
#define MAX 51
using namespace std;

char MATRIX[MAX][MAX];
int height[MAX][MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> MATRIX[i][j];
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> height[i][j];
        }
    }
}