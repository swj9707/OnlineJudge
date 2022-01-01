#include <iostream>
#define ll long long
using namespace std;

int main(){
    ll A, B, V;
    cin >> A >> B >> V;
    ll answer = 1;
    V -= A;
    ll C = A - B;
    if(V % C == 0) answer += V / C;
    else if(V < 0) answer = 1;
    else answer += V/C + 1;
    cout << answer << '\n';
}