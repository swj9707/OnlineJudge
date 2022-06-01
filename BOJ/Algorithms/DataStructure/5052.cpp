#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int testCase; cin >> testCase;
    while(testCase--){
        int N; cin >> N;
        bool ans = true;
        vector<string> vec;
        for(int i = 0; i < N; i++){
            string input; cin >> input;
            vec.push_back(input);
        }
        sort(vec.begin(), vec.end());
        for(int i = 0; i < N - 1; i++){
            int frontLen = vec[i].length();
            int rearLen = vec[i+1].length();
            if(rearLen > frontLen){
                string rearFront = vec[i+1].substr(0, frontLen);
                if(vec[i] == rearFront){
                    cout << "NO\n";
                    ans = false;
                    break;
                }
            }
        }
        if(ans) cout << "YES\n";
    }
}