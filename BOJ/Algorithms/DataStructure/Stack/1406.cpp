#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string tmp; cin >> tmp;
    int M; cin >> M;
    stack<char> l;
    stack<char> r;
    for(int i = 0; i < tmp.length(); i++){
        l.push(tmp[i]);
    }
    while(M--){
        char cmd;
        cin >> cmd;
        if(cmd == 'L'){
            if(!l.empty()){
                r.push(l.top());
                l.pop();
            }
        } else if (cmd == 'D'){
            if(!r.empty()){
                l.push(r.top());
                r.pop();
            }
        } else if (cmd == 'B'){
            if (!l.empty()){
                l.pop();
            }
        } else if (cmd == 'P'){
            char input; cin >> input;
            l.push(input);
        }
    }
    while(!l.empty()){
        r.push(l.top());
        l.pop();
    }
    while(!r.empty()){
        cout << r.top();
        r.pop();
    }

} 