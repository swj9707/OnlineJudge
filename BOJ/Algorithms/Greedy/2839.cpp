#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int answer = 0;
    while(N>=0){
        if(N%5 == 0) {
            answer += (N / 5);
            cout << answer << "\n";
            return 0;
        }
        N -= 3;
        answer += 1;
    }
    cout << "-1\n";
    return 0;
}