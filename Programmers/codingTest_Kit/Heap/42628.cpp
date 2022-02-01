#include <string>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    priority_queue<int, vector<int>, greater<int>> PQ_asc;
    priority_queue<int, vector<int>, less<int>> PQ_desc;
    char oper; int num;
    int length = 0;
    for(auto i : operations){
        istringstream ss(i);
        ss >> oper >> num;
        if(!length){
            while(!PQ_asc.empty()) PQ_asc.pop();
            while(!PQ_desc.empty()) PQ_desc.pop();
        }
        if(oper == 'I'){
            PQ_asc.push(num);
            PQ_desc.push(num);
            length++;
        }
        else{
            if(length){
                if(num == 1){
                    PQ_desc.pop();
                    length--;
                }
                else{
                    PQ_asc.pop();
                    length--;
                }
            }
        }
    }
    if(length){
        answer[0] = PQ_desc.top();
        answer[1] = PQ_asc.top();
    }

    return answer;
}