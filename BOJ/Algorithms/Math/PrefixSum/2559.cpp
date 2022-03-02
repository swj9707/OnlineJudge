#include <iostream>
#define MAX 100000
using namespace std;

int Arr[MAX]; 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> Arr[i];
    int sum = 0; 
    for(int i = 0; i < K; i++) sum += Arr[i];
    int left = 0, right = left + K;
    int answer = sum;
    while(true){
        if(right >= N) break;
        sum += Arr[right];
        sum -= Arr[left];
        answer = max(answer, sum);
        left++;
        right++;
    }
    cout << answer << '\n';
    return 0;
}   