#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N;
    cin >> N;
    int data[10] = {0,};//0,1,2,3,4,5,6,7,8,9
    while(N > 0){
        data[N%10]++;
        N /= 10;
    }
    int num = 0;
    for(int i = 0; i < 10; i++){
        if(i != 9 && i != 6) num = max(num, data[i]);
    }
    cout << max(num, (data[6]+ data[9] + 1)/2);
}