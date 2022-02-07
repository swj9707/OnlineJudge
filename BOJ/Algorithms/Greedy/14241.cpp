#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> Q;
    int N;
    int score = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        int input;
        cin >> input;
        Q.push(input);
    }

    while(Q.size() > 1){
        int first = Q.front();
        Q.pop();
        int second = Q.front();
        Q.pop();
        score += first * second;
        Q.push(first + second);
    }
    cout << score << '\n';
}