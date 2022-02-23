#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

struct cmp{
    bool operator()(int a, int b){
        if(abs(a) == abs(b)) return a > b;
        else return abs(a) > abs(b);
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    priority_queue<int, vector<int>, cmp> PQ;
    while(N--){
        int command ; cin >> command;
        if(command == 0){
            if(PQ.empty()) cout << "0\n";
            else {
                cout << PQ.top() << '\n';
                PQ.pop();
            }
        }
        else PQ.push(command);
    }
}