#include <iostream>
#define MAX 100001
#define ll long long
using namespace std;

ll arr[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    ll jwScore = arr[1];
    int i;
    for(i = 2; i <= N; i++){
        if(jwScore > arr[i]) jwScore += arr[i];
        else break;
    }
    if(i == N+1) cout << "Yes\n";
    else cout << "No\n";
}