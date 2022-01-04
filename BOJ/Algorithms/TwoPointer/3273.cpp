#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100001
using namespace std;
int Arr[MAX];
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int N, X;
    cin >> N;
    vector<int> vec(N);
    for(int i = 0; i < N; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());
    cin >> X;
    int result = 0, count = 0;
    int start = 0, end = N-1;
    while(1){
        if(start >= end) break;
        result = vec[start] + vec[end];
        if(result == X){
            count++;
            start++;
            end--;
        }
        else if(result < X) start++;
        else end--;
    }
    cout << count << '\n';
}