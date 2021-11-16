#include <iostream>

using namespace std;

int main(){
    int A, B;
    cin >> A >> B;
    int answer = 0;
    while(1){
        if(A > B){
            cout << "-1\n";
            break;
        }
        if (A == B){
            cout << answer + 1 << '\n';
            break;
        }
        if (B % 2 == 0){
            B /= 2;
        }
        else if(B % 10 == 1){
            B--;
            B /=10;
        }
        else{
            cout << "-1\n";
            break;
        }
        answer++;
    }
}