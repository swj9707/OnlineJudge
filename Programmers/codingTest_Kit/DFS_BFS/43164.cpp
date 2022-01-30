#include <string>
#include <vector>
#define MAX 10001
using namespace std;

bool visited[MAX];

bool DFS(string Current, vector<vector<string>> tickets, vector<string> &answer, int ticketIndex){
    answer.push_back(Current);
    if(ticketIndex == tickets.size()) return true;
    for(int i = 0; i < tickets.size(); i++){
        if(tickets[i][0] == Current && !visited[i]){
            visited[i] = true;
            bool T = DFS(tickets[i][1], tickets, answer, ticketIndex+1);
            if(T == true) return true;
            visited[i] = false;
        }
    }
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    return answer;
}