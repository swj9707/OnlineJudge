#include <string>
#include <vector>
#include <algorithm>
#define MAX 10001

using namespace std;

bool visited[MAX];

bool DFS(string current, vector<vector<string>> &tickets, vector<string> &answer, int ticketIndex){
    answer.push_back(current);
    if(ticketIndex == tickets.size()) return true;

    for(int i = 0; i < tickets.size(); i++){
        if(tickets[i][0] == current && !visited[i]){
            visited[i] = true;
            if(DFS(tickets[i][1], tickets, answer, ticketIndex+1)){
                return true;
            }
            visited[i] = false;
        }
    }
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end());
    DFS("ICN", tickets, answer, 0);
    return answer;
}