#include <iostream>
#include <deque>
#define MAX 500

using namespace std;

int matrix[MAX][MAX];
bool visit[MAX][MAX];
int n, m, count, answer;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> matrix[i][j];
    }
}