#include <iostream>

using namespace std;

int main(){
    long long A, B; cin >> A >> B;
    if(A > B){
        long long tmp;
        tmp = A;
        A = B;
        B = tmp;
    }
    if(A != B){
        cout << B - A - 1 << '\n';
        for(long long i = A + 1; i <= B - 1; i++) cout << i << " ";
        cout << '\n';
    }
    else cout << 0;
}