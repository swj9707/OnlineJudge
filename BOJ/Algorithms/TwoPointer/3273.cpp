#include <iostream>
#define MAX 100001
using namespace std;
int Arr[MAX];
int main(){
    int N, X;
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> Arr[i];
    cin >> X;
    int result = 0, count = 0;
    int start = 0, end = 1;
    while(start < end && end < N){
        result = Arr[start] + Arr[end];
        cout << start << " " << end << '\n';
        if(result == X){
            count++;
            start++;
            end = start + 1;
        }
        else end++;
    }
    cout << count << '\n';
}