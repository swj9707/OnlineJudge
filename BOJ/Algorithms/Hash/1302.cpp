#include <iostream>
#include <map>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    map<string, int> mp;
    for(int i = 0; i < N; i++){
        string tmp;
        cin >> tmp;
        mp[tmp]++;
    }
    string answer = "";
    int maxValue = 0;
    for(auto i : mp){
        if(i.second > maxValue){
            maxValue = i.second;
            answer = i.first;
        }
    }
    cout << answer << '\n';
}