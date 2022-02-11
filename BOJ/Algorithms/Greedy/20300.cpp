#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    long long answer = 0;
    cin >> N;
    int left = 0, right = N-1;
    vector<long long> data(N);
    for(int i = 0; i < N; i++) cin >> data[i];
    sort(data.begin(), data.end());
    if(N % 2 == 0){
        while(left <= right){
            long long tmp = data[left] + data[right];
            left++; right--;
            answer = max(answer, tmp); 
        }
    }
    else{
        answer = data[right];
        right--;
        while(left <= right){
            long long tmp = data[left] + data[right];
            left++; right--;
            answer = max(answer, tmp);
        }
    }
    cout << answer << '\n';
}