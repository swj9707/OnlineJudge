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
    int answer = 0;
    for(int i = 0; i < N; i++) cin >> vec[i];
    int maxIndex = max_element(vec.begin(), vec.end()) - vec.begin();
    for(int i = maxIndex+1; i < N; i++){
        answer = max(answer, vec[i]);
    }
    cout << answer << '\n';
}