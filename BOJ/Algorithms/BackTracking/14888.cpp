#include <iostream>

using namespace std;
int maximum = -98765432;
int minimum = 98765432;
int N;
int operands[11];
int operators[4];

void DFS(int result, int idx){
    if(idx == N){
        maximum = max(maximum, result);
        minimum = min(minimum, result);
        return;
    }
    for(int i = 0; i < 4; i++){
        if(operators[i] > 0){
            operators[i]--;
            if(i == 0) DFS(result + operands[idx], idx + 1);
            else if(i == 1) DFS(result - operands[idx], idx + 1);
            else if(i == 2) DFS(result * operands[idx], idx + 1);
            else DFS(result / operands[idx], idx + 1);
            operators[i]++;
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> operands[i];
    for(int i = 0; i < 4; i++) cin >> operators[i];
    DFS(operands[0],1);
    cout << maximum << '\n';
    cout << minimum << '\n';
    return 0;
}