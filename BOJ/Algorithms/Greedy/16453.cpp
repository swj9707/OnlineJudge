#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int Arr[MAX];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, L;
    cin >> N >> L;
    for(int i = 1; i <= N; i++) cin >> Arr[i];
    sort(Arr+1, Arr+N+1);
    for(int i = 1; i <= N; i++){
        if(Arr[i] <= L) L++;
        else break;
    }
    cout << L << '\n';
}