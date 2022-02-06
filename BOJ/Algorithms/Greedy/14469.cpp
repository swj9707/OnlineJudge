#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<pair<int, int>> vec;
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        vec.push_back({a, b});
    }
    sort(vec.begin(), vec.end());
    int answer = vec[0].first + vec[0].second;
    for(int i = 1; i < N ; i++){
        if(answer <= vec[i].first){
            answer = vec[i].first + vec[i].second;
        }
        else{
            answer += vec[i].second;
        }
    }
    cout << answer << '\n';
}