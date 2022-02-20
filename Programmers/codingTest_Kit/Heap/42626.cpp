#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> PQ;
    for(int i = 0; i < scoville.size(); i++) PQ.push(scoville[i]); 
    int count = 0;
    while(PQ.size() > 1 && PQ.top() < K){
        int first = PQ.top();
        PQ.pop();
        int second = PQ.top();
        PQ.pop();
        int result = first + (second * 2);
        PQ.push(result);
        count++;
    }
    if(PQ.top() < K) count = -1;
    return count;
}