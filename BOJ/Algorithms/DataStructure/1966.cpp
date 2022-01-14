#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int N, find;
        cin >> N >> find;
        int count = 0;
        queue<pair<int, int>> q;
        priority_queue<int, vector<int>, less<int>> pq;
        for(int j = 0; j < N; j++){
            int tmp;
            cin >> tmp;
            q.push({j, tmp});
            pq.push(tmp);
        }
        while(!q.empty()){
            int index = q.front().first;
            int data = q.front().second;
            q.pop();
            if(pq.top() == data){
                pq.pop();
                count++;
                if(index == find){
                    cout << count << '\n';
                    break;
                }
            }
            else q.push({index, data});
        }
    }
}