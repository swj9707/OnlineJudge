#include <iostream>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    int answer = 0;
    int maxValue = 0;
    cin >> N;
    map<int, int> mp;
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        mp[tmp]++;
    }
    for(auto i : mp){
        if(maxValue < i.second){
            maxValue = i.second;
            answer = i.first;
        }
    }
    cout << answer << '\n';
}