#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    vector<int> after;
    queue<int> bridge;
    int sum = 0, idx = 0;
    int trucks = truck_weights.size();
    for(int i = 0; i < bridge_length ; i++) bridge.push(-1);
    while(after.size() != trucks){
        if(sum + truck_weights[idx] < weight){
            sum += truck_weights[idx];
            bridge.pop();
            bridge.push(truck_weights[idx]);
            idx++;
        }
        else{
            if(bridge.front() != -1){ 
                sum -= bridge.front();
                after.push_back(bridge.front());
            }
            bridge.pop();
            bridge.push(-1);
        }
        answer++;
        cout << idx << '\n';
    }

    return answer;
}