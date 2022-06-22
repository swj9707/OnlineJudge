#include <iostream>
#include <stack>
#define ll long long
using namespace std;

ll arr[100002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    while(1){
        cin >> N;
        if(N == 0) break;
        ll answer = 0;
        stack<int> stk;
        fill_n(arr, 100002, 0);
        for(int i = 1; i <= N; i++){
            cin >> arr[i];
        }
        stk.push(0);

        for(int i = 1; i <= N+1; i++ ){
            while(!stk.empty() && arr[stk.top()] > arr[i]){
                ll height = arr[stk.top()];
                stk.pop();
                ll width = i -  stk.top() - 1;
                ll area = height * width;
                answer = max(answer, area);
            }
            stk.push(i);
        }
        cout << answer << '\n';
    }
}