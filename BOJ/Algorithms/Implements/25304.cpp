#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long X;  
    int N; 
    cin >> X >> N;
    long long sum = 0;
    for(int i = 0; i < N; i++){
        int cost, n;
        cin >> cost >> n;
        sum += cost * n;
    }
    if(X == sum){
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}