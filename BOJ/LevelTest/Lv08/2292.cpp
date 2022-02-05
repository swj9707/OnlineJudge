#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int i = 0;
    for(int sum = 2; sum <= N; i++){
        sum += 6 * i;
    }
    if(N == 1) i = 1;
    cout << i;
    return 0;
}