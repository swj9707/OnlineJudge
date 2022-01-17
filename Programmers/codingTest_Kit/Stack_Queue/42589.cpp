#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> tmp;
    for(int i = 0; i < progresses.size(); i++){
        int leftRate = 100 - progresses[i];
        int date = leftRate / speeds[i];
        if(leftRate % speeds[i] != 0) date += 1;
        tmp.push(date);        
    }
    int start = tmp.front();
    int count = 0;
    while(!tmp.empty()){
        if(tmp.front() <= start){
            tmp.pop();
            count++;
        }
        else{
            if(count > 0){
                start = tmp.front();
                answer.push_back(count);
                count = 0;
            }
        }
    }
    answer.push_back(count);
    return answer;
}