#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string tmp = "";
    stack<char> stk;
    while(true){
        getline(cin, tmp);
        if(tmp == ".") break;
        while(!stk.empty()) stk.pop();
        for(auto i : tmp){
            if(i == '[' || i == '(') stk.push(i);
            else{
                if((i == ']' && stk.top() == '[') || 
                (i == ')' && stk.top() == '(')) stk.pop();
            }
        }
        if(stk.empty()) cout << "yes\n";
        else cout << "no\n";
    }
}