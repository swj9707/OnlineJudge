#include <iostream>
#include <stack>

using namespace std;

int main(){
    string tmp;
    while(true){
        getline(cin, tmp);
        if(tmp == ".") break;
        stack<char> stk;
        bool check = true;
        for(auto i : tmp){
            if(i == '[' || i == '(') stk.push(i);
            else if(i == ')'){
                if(!stk.empty() && stk.top() == '(') stk.pop();
                else{
                    check = false;
                    break;
                }
            }
            else if(i == ']'){
                if(!stk.empty() && stk.top() == '[') stk.pop();
                else{
                    check = false;
                    break;
                }
            }
        }
        if(check && stk.empty()) cout << "yes\n";
        else cout << "no\n";
    }
}