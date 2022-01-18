#include <string>
#include <vector>
#define MAX 201
using namespace std;

int MATRIX[MAX][MAX];
bool Visit[MAX];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0; i < computers.size(); i++){
        for(int j = 0; j < n; j++){
            if(i != j){
                if(computers[i][j] == 1){
                    MATRIX[i][j] = 1;
                    MATRIX[j][i] = 1;
                }
            }
        }
    }
    return answer;
}