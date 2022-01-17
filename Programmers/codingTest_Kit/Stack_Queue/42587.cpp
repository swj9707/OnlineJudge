#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> Q;
    priority_queue<int, vector<int>, less<int>> PQ;
    for(int i = 0; i < priorities.size(); i++) {
        Q.push({i, priorities[i]});
        PQ.push(priorities[i]);
    }
    int count = 0;
    while(!Q.empty()){
        int index = Q.front().first;
        int data = Q.front().second;
        Q.pop();
        if(PQ.top() == data){
            PQ.pop();
            count++;
            if(location == index){
                answer = count;
                break;
            }
        }
    }
    return answer;
}