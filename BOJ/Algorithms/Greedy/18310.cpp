#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    int answer;
    cin >> N;
    vector<int> vec(N);
    for(int i = 0; i < N; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
    if(N % 2 == 1){
        answer = vec[N/2];
    }
    else{
        int mid1, mid2;
        int sum1 = 0, sum2 = 0;
        mid1 = vec[N/2-1];
        mid2 = vec[N/2];
        for(int i = 0; i < N; i++){
            sum1 += abs(vec[i] - mid1);
            sum2 += abs(vec[i] - mid2);
        }
        if(sum1 <= sum2) answer = mid1;
        else answer = mid2;
    }
    cout << answer << '\n';
}