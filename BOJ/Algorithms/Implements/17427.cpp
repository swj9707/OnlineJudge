#include <iostream>
#define ll long long
using namespace std;

int main(){
    int N;
    ll answer = 0;
    cin >> N;
    for(int i = 1; i <= N; i++){
        answer += (N / i) * i;
    }
    cout << answer;
}