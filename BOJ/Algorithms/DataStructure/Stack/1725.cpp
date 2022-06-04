#include <iostream>
#include <stack>
using namespace std;

int arr[100002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int answer = 0;
    stack<int> stk;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    
    stk.push(0);

    for(int i = 1; i <= N+1; i++ ){
        while(!stk.empty() && arr[stk.top()] > arr[i]){
            int height = arr[stk.top()];
            stk.pop();
            int width = i -  stk.top() - 1;
            answer = max(answer, height * width);
        }
        stk.push(i);
    }
    cout << answer << '\n';
}