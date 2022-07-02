#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;
    stack<char> stk;
    for(auto i : s){
        stk.push(i);
        if(stk.size() > 1){
            char first = stk.pop();
            char second = stk.pop();
            if(first != second){
                stk.push(second);
                stk.push(first);
            }
        }
    }
    if(stk.size() == 0) answer = 1;
    else answer = 0;

    return answer;
}