#include <iostream>
#include <string>
using namespace std;

int main(){
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++){
        int tmp = i;
        bool check = false;
        while(tmp){
            int digit = tmp % 10;
            if(digit == 3 || digit == 6 || digit == 9) {
                cout << "-";
                check = true;
            }
            //else cout << digit;
            tmp /= 10;
        }
        if(check == false) cout << i;
        cout << " ";
    }
}