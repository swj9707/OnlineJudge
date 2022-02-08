#include <string>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

int Parent[MAX];

int getParent(int num){
    if(num == Parent[num]) return num;
    return Parent[num] = getParent(Parent[num]);
}

void unionParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a != b) Parent[a] = b;
}

bool findParent(int a, int b){
    a = getParent(a);
    b = getParent(b);
    if(a == b) return true;
    else return false;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<pair<int, pair<int, int>>> vec;
    for(int i = 0; i < costs.size(); i++){
        int start = costs[i][0];
        int end = costs[i][1];
        int cost = costs[i][2];
        vec.push_back({cost, {start, end}});
    }
    for(int i = 0 ; i < n; i++) Parent[i] = i;
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); i++){
        int start = vec[i].second.first;
        int end = vec[i].second.second;
        int cost = vec[i].first;
        if(!findParent(start, end)){
            answer += cost;
            unionParent(start, end);
        }
    }
    return answer;
}