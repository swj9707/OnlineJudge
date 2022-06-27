#include <iostream>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    deque<int> first;
    deque<int> second;
    int order = 1;
    while(N--){
        int x; cin >> x;
        first.push_back(x);
    }
    while(!first.empty()){
        int cur = first.front();
        if(cur == order){
            first.pop_front();
            order++;
        } else {
            if(!second.empty() && second.front() == order){
                second.pop_front();
                order++;
            }
            else {
                first.pop_front();
                second.push_front(cur);
            }
        }
    }
    while(!second.empty()){
        int cur = second.front();
        if(cur != order){
            cout << "Sad\n";
            return 0;
        }
        second.pop_front();
        order++;
    }
    cout << "Nice\n";
    return 0;
}