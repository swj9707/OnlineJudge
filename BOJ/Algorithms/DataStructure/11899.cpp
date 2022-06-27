#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string tmp; cin >> tmp;
    stack<char> stk;
    for(int i = 0; i < tmp.length(); i++){
        stk.push(tmp[i]);
        if(stk.size() > 1){
            char first = stk.top();
            stk.pop();
            char second = stk.top();
            stk.pop();
            if(!(second == '(' && first == ')')){
                stk.push(second);
                stk.push(first);
            }
        }
    }
    cout << stk.size() << '\n';
}