#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    vector<long long> vec(N);
    for(int i = 0; i < N; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
    long long sum = 0;
    long long deltaAbs = 2000000000;
    int left = 0, right = N-1;
    long long answerLeft, answerRight;
    while(left < right){
        sum = vec[left] + vec[right];
        if(deltaAbs > abs(sum)){
            deltaAbs = abs(sum);
            answerLeft = vec[left];
            answerRight = vec[right];
            if(sum == 0) break;
        }
        if(sum < 0) left++;
        else right--;
    }
    cout << answerLeft << " " << answerRight << '\n';
}