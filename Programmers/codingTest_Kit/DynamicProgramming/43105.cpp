#include <string>
#include <vector>
#include <iostream>
#define MAX 500
using namespace std;
int DP[500][500];
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int height = triangle.size();
    
    DP[0][0] = triangle[0][0];
    
    for(int i = 0; i < height - 1 ; i++){
        for(int j = 0; j < triangle[i+1].size()-1; j++){
            DP[i+1][j] = max(DP[i+1][j], DP[i][j] + triangle[i+1][j]);
            DP[i+1][j+1] = max(DP[i+1][j+1], DP[i][j] + triangle[i+1][j+1]);
        }
    }

    for(int i = 0; i < triangle[height-1].size(); i++){
        answer = max(answer, DP[height-1][i]);
    }
    return answer;
}