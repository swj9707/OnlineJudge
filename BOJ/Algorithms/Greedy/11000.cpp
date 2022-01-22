#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<pair<int, int>> classes(N);
    for(int i = 0; i < N; i++) cin >> classes[i].first >> classes[i].second;
    sort(classes.begin(), classes.end());

    priority_queue<int, vector<int>, greater<int>> PQ;
    PQ.push(classes[0].second);
    for(int i = 1; i < N; ++i){
        if(PQ.top() <= classes[i].first){
            PQ.pop();
            PQ.push(classes[i].second);
        }
        else{
            PQ.push(classes[i].second);
        }
        cout << PQ.top() << " " << PQ.size() <<'\n';
    }

    cout << PQ.size() << '\n';
}