#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> vec(N);
    for(int i =0; i < N; i++){
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    long long answer = 0;
    int rank = 1;
    for(int i = N-1; i>=0; i--){
        answer += max(0, vec[i]-(rank++ -1));
    }
    cout << answer << '\n';
}