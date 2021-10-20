#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int answer = 0;
    while(N != 0){
        answer += N % 10;
        N /= 10;
    }
    cout << answer << '\n';
}