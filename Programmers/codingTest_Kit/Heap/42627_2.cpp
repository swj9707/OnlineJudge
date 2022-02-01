#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> PQ;
    int length = jobs.size();
    int idx = 0, time = 0;

    while(idx < length || !PQ.empty()){
        if(idx < length && time >= jobs[idx][0]){
            PQ.push(jobs[idx]);
            idx++;
            continue;
        }
        if(!PQ.empty()){
            time += PQ.top()[1];
            answer += time - PQ.top()[0];
            PQ.pop();
        }
        else time = jobs[idx][0];
    }

    return answer / length;
}