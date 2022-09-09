#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N1, N2; 
    int T;
    vector<pair<char, int>> vec;
    cin >> N1 >> N2;
    string S1, S2;
    cin >> S1;
    cin >> S2;

    for(int i = S1.size() - 1; i >= 0; i--){
        vec.push_back({S1[i], 0});
    }

    for(int i = 0; i < S2.size(); i++){
        vec.push_back({S2[i], 1});
    }

    cin >> T;
    int length = S1.size() + S2.size();

    while(T--){
        for(int i = 0 ; i < length; i++){
            if(vec[i].second == 0 && vec[i + 1].second == 1){
                swap(vec[i], vec[i+1]);
                i++;
            }
        }
    }

    for(int i = 0; i < length; i++){
        cout << vec[i].first;
    }
    cout << '\n';

}