#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;
    queue<int> q;
    vector<int> answer;
    for(int i = 1; i <= N; i++) q.push(i);
    while(!q.empty()){
        for(int i = 0; i < K-1; i++){
            q.push(q.front());
            q.pop();
        }
        answer.push_back(q.front());
        q.pop();   
    }
    cout << "<";
    for(int i = 0; i < answer.size() - 1; i++){
        cout << answer[i] <<", ";
    }
    cout << answer[answer.size()-1] <<">\n";
    return 0;
}