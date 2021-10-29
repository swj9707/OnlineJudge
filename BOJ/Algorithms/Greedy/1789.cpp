#include <iostream>

using namespace std;

int main(){
    long long S;
    cin >> S;
    long long tmp = 1;
    long long answer = 0;
    while(true){
        S -= tmp;
        if (S >= 0){
            answer += 1;
            tmp += 1;
        }
        else{
            cout << answer << '\n';
            return 0;
        }
    }
}