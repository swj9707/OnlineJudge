#include <iostream>
#define MAX 100001
using namespace std;

int arr[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];

    int up = 1, down = 1;
    int result, answer = 1;
    for(int i = 1; i < N; i++){
        if(arr[i] <= arr[i+1]) up++;
        else up = 1;
        if(arr[i] >= arr[i+1]) down++;
        else down = 1;

        result = max(up, down);
        answer = max(answer, result);
    }
    cout << answer << '\n';
}