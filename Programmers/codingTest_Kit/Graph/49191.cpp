#include <string>
#include <vector>
#include <iostream>
#define MAX 101
#define INF 9876543231
using namespace std;

int MATRIX[MAX][MAX];

void floydWarshall(int n){
        for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++) 
            MATRIX[i][j] = min(MATRIX[i][j], MATRIX[i][k] + MATRIX[k][j]);
        }
    }
}


int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) MATRIX[i][j] = INF;
    }
    for(int i = 0; i < results.size() ; i++){
        MATRIX[results[i][0]][results[i][1]] = 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cout << MATRIX[i][j] << " ";
        cout << '\n';
    }

    floydWarshall(n);
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) cout << MATRIX[i][j] << " ";
        cout << '\n';
    }

    for(int i = 1; i <= n; i++){
        int count = 0;
        for(int j = 1; j <= n; j++){
            if(MATRIX[i][j] != INF || MATRIX[j][i] != INF) count++;
        }
        cout << count << '\n';
        if(count == n - 1) answer++;
    }
    return answer;
}