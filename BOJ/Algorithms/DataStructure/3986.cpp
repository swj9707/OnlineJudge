#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    int answer = 0;
    while(N--){
        string tmp; cin >> tmp;
        stack<char> stk;
        for(int i = 0; i < tmp.size(); i++){
            stk.push(tmp[i]);
            if(stk.size() > 1){
                char first = stk.top();
                stk.pop();
                char second = stk.top();
                stk.pop();
                if(first != second){
                    stk.push(second);
                    stk.push(first);
                }
            }
        }
        if(stk.empty()) answer++;
    }
    cout << answer << '\n';
    return 0;
}