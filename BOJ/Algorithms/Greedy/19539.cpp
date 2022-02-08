#include <iostream>

using namespace std;

int arr[100001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    int one = 0, two = 0;

    for(int i = 1; i <= N; i++){
        two += arr[i] / 2;
        one += arr[i] % 2;
    }
    if((two - one) % 3 == 0 && two >= one){
        cout << "YES\n";
    }
    else cout << "NO\n";
}