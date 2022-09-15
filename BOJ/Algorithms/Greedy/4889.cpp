#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string Str;
    int caseNum = 1;
    while(1){
        cin >> Str;
        if(Str[0] == '-'){
            break;
        }
        int result = 0;
        stack<char> stk;
        for(auto i : Str){
            if(i == '}' && !stk.empty() && stk.top() == '{'){
                stk.pop();
            } else {
                stk.push(i);
            }
        }

        while(!stk.empty()){
            char first = stk.top();
            stk.pop();
            char second = stk.top();
            stk.pop();
            if(first == second) result++;
            else result += 2;
        }
        cout << caseNum << ". " << result << '\n';
        caseNum++;
    }
    return 0;
}