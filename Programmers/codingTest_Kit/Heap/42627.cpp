#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    int idx = 0, time = 0;
    int length = jobs.size();
    while(idx < length || !PQ.empty()){
        if(idx < length && time >= jobs[idx][0]){
            PQ.push({jobs[idx][1], jobs[idx][0]});
            idx++;
            continue;
        }
        if(!PQ.empty()){
            time += PQ.top().first;
            answer += time - PQ.top().second;
            PQ.pop();
        }
        else{
            time = jobs[idx][0];
        }
    }

    return answer / length;
}