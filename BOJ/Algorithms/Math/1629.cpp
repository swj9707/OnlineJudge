#include <iostream>

using namespace std;

int main(){
    long long int A, B, C;
    cin >> A >> B >> C;
    long long Answer = 1;
    for(int i = 0; i < B; i++){
        Answer *= A % C;
    }
    cout << Answer << '\n';
}