#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string S;
    getline(cin, S);
    deque<char> dq;
    string answer = "";
    bool check = false;
    for(auto i : S){
        if(i == '<'){
            while(!dq.empty()){
                char a = dq.back();
                answer += a;
                dq.pop_back();
            }
            answer += '<';
            check = true;
        } else if (i == '>'){
            while(!dq.empty()){
                char a = dq.front();
                answer += a;
                dq.pop_front();
            }
            answer += '>';
            check = false;
        } else if (i == ' '){
            if(!check){
                while(!dq.empty()){
                    char a = dq.back();
                    answer += a;
                    dq.pop_back();
                }
                answer += ' ';
            } else {
                dq.push_back(i);
            }
        } else {
            dq.push_back(i);
        }
    }
    while(!dq.empty()){
        char a = dq.back();
        answer += a;
        dq.pop_back();
    }
    cout << answer << '\n';
}