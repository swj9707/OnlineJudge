#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str; cin >> str;
    stack<char> stk;
    int answer = 0, tmp = 1;
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '('){
            tmp *= 2;
            stk.push('(');
        } else if (str[i] == '[') {
            tmp *= 3;
            stk.push('[');
        } else if (str[i] == ')') {
            if(stk.empty() || stk.top() != '('){
                answer = 0;
                break;
            } else if (str[i-1] == '('){
                answer += tmp;
                tmp /= 2;
                stk.pop();
            } else {
                tmp /= 2;
                stk.pop();
            }
        } else if (str[i] == ']'){
            if(stk.empty() || stk.top() != '['){
                answer = 0;
                break;
            } else if (str[i-1] == '['){
                answer += tmp;
                tmp /= 3;
                stk.pop();
            } else {
                tmp /= 3;
                stk.pop();
            }
        }
    }
    if(!stk.empty()) answer = 0;
    cout << answer << '\n';
    return 0;
}