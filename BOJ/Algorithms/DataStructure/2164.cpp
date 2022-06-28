#include <iostream>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    deque<int> dq;
    for(int i = 1; i <= N; i++){
        dq.push_back(i);
    }
    while(dq.size() != 1){
        dq.pop_front();
        int first = dq.front();
        dq.pop_front();
        dq.push_back(first);
    }
    cout << dq.front() << '\n';
}