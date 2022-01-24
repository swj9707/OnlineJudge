#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    int N;
    cin >> N;
    stack<int> stk;
    string answer = "";
    int cnt = 1;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        if(num >= cnt){
            while(num + 1 != cnt){
                stk.push(cnt++);
                answer += "+\n";
            }
            stk.pop();
            answer += "-\n";
        }
        else{
            if(stk.top() == num){
                stk.pop();
                answer += "-\n";
            }
            else{
                answer = "NO\n";
                break;
            }
        }
    }
    cout << answer << '\n';
}