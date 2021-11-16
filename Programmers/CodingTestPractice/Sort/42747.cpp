#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool comp(int a, int b){
    return a > b;
}
int solution(vector<int> citations) {
    int answer = 1;
    sort(citations.begin(), citations.end(), comp);
    if(!citations[0]) return 0;
    for(int i = 0; i < citations.size(); i++){
        if(citations[i] > i) answer++;
        else break;
    }
    return answer;
}