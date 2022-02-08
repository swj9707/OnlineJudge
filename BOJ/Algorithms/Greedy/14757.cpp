#include <iostream>
#include <set>
#define MAX 1001

using namespace std;

int MATRIX[MAX][MAX];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    set<int> maxSet;
    int sum = 0;
    for(int i = 1; i <= N; i++){
        int inputValue;
        int maxValue = 0;
        for(int j = 1; j <= M; j++) {
            cin >> inputValue;
            sum += inputValue;
            MATRIX[i][j] = inputValue;
            maxValue = max(inputValue, maxValue);
        }
        maxSet.insert(maxValue);
    }

    for(int i = 1; i <= M; i++){
        int maxValue = 0;
        for(int j = 1; j <= N; j++){
            maxValue = max(maxValue, MATRIX[j][i]);
        }
        maxSet.insert(maxValue);
    }
    for(auto i : maxSet){
        sum -= i;
    }
    cout << sum << '\n';
}