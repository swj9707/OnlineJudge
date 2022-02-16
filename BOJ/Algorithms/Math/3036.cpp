#include <iostream>

using namespace std;

int Arr[101];
int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int res;
    for (int i = 0; i < N; i++) cin >> Arr[i];
    for(int i = 1; i < N; i++){
        if(Arr[0] > Arr[i]) res = gcd(Arr[0], Arr[i]);
        else res = gcd(Arr[i], Arr[0]);
        cout << Arr[0] / res << "/" << Arr[i] / res << '\n';
    }
}