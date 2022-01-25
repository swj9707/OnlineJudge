#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int first;
    int answer = 0;
    priority_queue<int, vector<int>, less<int>> PQ;
    cin >> first;
    for(int i = 1; i < N; i++){
        int tmp;
        cin >> tmp;
        PQ.push(tmp);
    }
    while(!PQ.empty()){
        int tmp = PQ.top();
        if(tmp >= first){
            first += 1;
            tmp -= 1;
            answer++;
            PQ.pop();
            PQ.push(tmp);
        }
        else PQ.pop();
    }
    cout << answer << '\n';
}