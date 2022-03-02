#include <iostream>
#define MAX 100001
#define ll long long
using namespace std;

ll DP[MAX];
ll sum[MAX];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill_n(DP, MAX, 1);
    for(ll i = 2; i < MAX; i++){
        ll j = 1;
        while(i * j < MAX){
            DP[i*j] += i;
            j++;
        }
    }
    for(int i = 1; i < MAX; i++){
        sum[i] += sum[i-1] + DP[i];
    }
    int T; cin >> T;
    while(T--){
        int X; cin >> X;
        cout << sum[X] << '\n';
    }
}