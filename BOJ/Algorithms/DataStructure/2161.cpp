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
    while(dq.size() > 1){
        int front = dq.front();
        cout << front << " ";
        dq.pop_front();
        int nextFront = dq.front();
        dq.pop_front();
        dq.push_back(nextFront);
    }
    cout << dq.front() << "\n";
    return 0;
}