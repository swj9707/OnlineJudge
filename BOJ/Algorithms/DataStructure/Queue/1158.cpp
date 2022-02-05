#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> Q;
    int N, K;
    cin >> N >> K;
    for(int i = 1; i <= N; i++) Q.push(i);
    int seq = 1;
    vector<int> answer;
    while(answer.size() != N){
        int tmp = Q.front();
        if(seq == K){
            Q.pop();
            answer.push_back(tmp);
            seq = 1;
        }
        else{
            Q.pop();
            Q.push(tmp);
            seq++;
        }
    }
    cout << "<";
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i];
        if(i != answer.size()-1)cout << ", ";
    }
    cout << ">\n";
}