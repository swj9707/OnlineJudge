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
    int start = 1, end = 2;
    while(start < end && end <= N){
        result = Arr[start] + Arr[end];
        if(result == X){
            count++;
            start++;
            end = start + 1;
        }
        else{
            if(end != N) end++;
            else {
                start++;
                end = start + 1;
            }
        }
    }
    cout << count << '\n';
}