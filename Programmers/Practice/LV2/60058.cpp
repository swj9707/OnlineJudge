#include <bits/stdc++.h>

using namespace std;

bool check(string p){
    stack<char> st;
    
    for(auto c: p) {
        if(c == '(') st.push(c);
        else {
            if(st.empty()) return false;
            st.pop();
        }
    }
    
    return st.empty();    
}

string solution(string p) {
    if(p.empty()) return p;
    string answer = "";
    
    string u = "", v = "";
    int l = 0, r = 0;

    return answer;
}