#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int data[10];
        int sum = 0;
        for(int j = 0 ; j < 10; j++) cin >> data[j];
        for(int j = 0 ; j < 10; j++) sum += data[j];
        float answer = (float)sum / 10 + 0.5;
        cout << "#" << i+1 << " " << floor(answer) << '\n';
    }
    return 0;
}
        