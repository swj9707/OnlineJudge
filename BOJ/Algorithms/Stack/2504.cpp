#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string tmp;
    stack<char> stk;
    getline(cin, tmp);
    int answer = 0;
    for(auto i : tmp){
        if(i == '(') stk.push(i);
        else if(i ==')'){
            
        } 
    }
    return 0;
}