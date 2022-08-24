#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> bridgeDq;
    deque<int> Que;
    int N, W, L;
    int time = 0;
    int nowWeight = 0;
    int count = 0;
    cin >> N >> W >> L;
    
    for(int i = 0; i < W; i++){
        bridgeDq.push_back(0);
    }

    for(int i = 0; i < N; i++){
        int data; cin >> data;
        Que.push_back(data);
    }

    while(count != N){
        if(bridgeDq.front() != 0){
            nowWeight -= bridgeDq.front();
            count++;
        }
        bridgeDq.pop_front();

        if(nowWeight < L){
            if(!Que.empty() && nowWeight + Que.front() <= L){
                nowWeight += Que.front();
                bridgeDq.push_back(Que.front());
                Que.pop_front();
            } else {
                bridgeDq.push_back(0);
            }
        } else {
            bridgeDq.push_back(0);
        }
        time++;
    }

    cout << time << '\n';
}