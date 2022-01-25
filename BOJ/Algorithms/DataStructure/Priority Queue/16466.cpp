#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> PQ;
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        PQ.push(tmp);
    }
    int answer = 0;
    while(1){
        int tmp = PQ.top();
        if((tmp - answer) == 1){
            answer = tmp;
            PQ.pop();
        }
        else{ 
            answer++;
            break;
        }
    }
    cout << answer << '\n';
}