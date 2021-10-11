#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int data[10];
        int answer = 0;
        for(int j = 0 ; j < 10; j++) cin >> data[j];
        for(int j = 0 ; j < 10; j++) answer += data[j];
        cout << "#" << i+1 << " " << ceil(answer / 10) << '\n';
    }
    return 0;
}
        