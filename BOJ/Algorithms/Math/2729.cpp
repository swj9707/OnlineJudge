#include <iostream>

using namespace std;

int tenCovertTwo(int num){
    int result = 0;
    for(int i = 1; num > 0; i *= 10){
        int binary = num % 2;
        result += binary * i;
        num /=2 ;
    }
    return result;
}

int twoConvertTen(int num){
    int result = 0, mul = 1;
    while(num > 0){
        if(num %2) result += mul;
        mul *= 2;
        num /= 10;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int tc = 0; tc < T; tc++){
        int A, B;
        cin >> A >> B;
        
    }
}