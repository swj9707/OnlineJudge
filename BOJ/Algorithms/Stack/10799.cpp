#include <iostream>
#include <stack>
using namespace std;

int main(){
    string tmp;
    stack<char> stk;
    int answer = 0;
    cin >> tmp;
    for(int i = 0; i < tmp.size(); i++){
        if(tmp[i] == '(') stk.push(i);
        else{
            if(tmp[i - 1] == '('){//레이저다?
                stk.pop();
                answer += stk.size();
            } 
            else{//파이프가 끊켰다?
                answer += 1;
                stk.pop();
            }
        }
    }
    cout << answer << '\n';
}