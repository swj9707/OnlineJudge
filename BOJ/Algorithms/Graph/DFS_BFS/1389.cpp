#include <iostream>
#include <algorithm>
#define MAX 101
using namespace std;

int N, M;
int MATRIX[MAX][MAX];

void floyd(){
    for(int k = 1; k <= N; k++){
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                if(i == j) continue; //자기 자신은 어차피 의미없음
                else if(MATRIX[i][k] != 0 && MATRIX[k][j] != 0){//i와 k간에 상관관계가 있고 k와 j간에 상관관계가 있다?
                    if(MATRIX[i][j] == 0) MATRIX[i][j] = MATRIX[i][k] + MATRIX[k][j];//만약 i와 j간에 상관관계가 없다면 둘 사이를 연결해준다
                    else MATRIX[i][j] = min(MATRIX[i][j], MATRIX[i][k] + MATRIX[k][j]);//그게 아니면 i와 j 그리고 k랑 사이에 낀 상관관계 중 작은놈을 연결해준다
                }
            }
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        MATRIX[a][b] = 1;
        MATRIX[b][a] = 1;
    }
    floyd();
    int answer = 1;
    int result = 9999999;
    for(int i = 1; i <= N; i++){
        int tmpResult = 0;
        for(int j = 1; j <= N; j++){
            tmpResult += MATRIX[i][j];
        }
        if(result > tmpResult){
            result = tmpResult;
            answer = i;
        }
    }
    cout << answer << '\n';
}