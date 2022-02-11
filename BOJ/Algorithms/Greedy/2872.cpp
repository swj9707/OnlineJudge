#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> vec(N);
    vector<int> tmp;
    int answer = 0;
    for(int i = 0; i < N; i++) {
        cin >> vec[i];
    }
    int maxValue = N;
    for(int i = N -1 ; i >= 0; i--){
        if(vec[i] == maxValue){
            tmp.push_back(maxValue);
            maxValue -= 1;
        }
    }
    answer = N - tmp.size();
    cout << answer << '\n';
}