#include <iostream>
#include <vector>
#include <queue>
#define MAX (long long) 2 << 31
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int K, N;
    cin >> K >> N;
    vector<int> vec;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(int i = 0; i < K; i++){
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
        pq.push(tmp);
    }
    int count = 0;
    long long cur = 0;
    for(int i = 0; i < N; i++){
        cur = pq.top();
        pq.pop();
        for(auto a : vec){
            if((long long)a * cur >= MAX) break;
            pq.push(a * cur);
            if(cur % a == 0) break;
        }
    }
    cout << cur << '\n';
}