#include <iostream>

using namespace std;

long long solution(int price, int money, int count){
    long long answer = -1;
    long long Amount = 0;
    for(int i = 1; i <= count; i++){
        Amount += price * i;
    }
    answer = (Amount - money > 0) ? Amount - money : 0;
    return answer;
}

int main(){
    cout << solution(3, 20, 4);
}