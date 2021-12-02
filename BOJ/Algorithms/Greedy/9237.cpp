#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> vec(N);
    int answer = 0;
    for(int i = 0; i < N; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
    for(int i = 0; i < N; i++){
        answer = max(answer, vec[i] + i + 1);
    }
    cout << answer + 1 << '\n';
}