#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long answer = 0;
    for(int i =0; i < n; i++){
        int data; cin >> data; pq.push(data);
    }
    for(int i = 0; i < m; i++){
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        pq.push(a+b);
        pq.push(a+b);
    }
    for(int i = 0 ; i < n; i++){
        answer += pq.top();
        pq.pop();
    }
    cout << answer << '\n';
}