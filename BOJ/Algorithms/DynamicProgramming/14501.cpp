#include <iostream>
#include <algorithm>

using namespace std;

int T[18],P[18],DP[18];

int main(){
    int N;

    cin >> N;
    for(int i = 1; i<=N; i++){
        cin>>T[j]>>P[j];
    }

    for(int j = N ; j>0; j--){
        if(l[j]>i-j+1) r[j] = r[j+1];
        else r[j] = max(c[j] + r[j+l[j]],r[j+1]);
    }

    cout << r[1];
}