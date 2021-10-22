#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int Answer = 0;
    for(int i = 0; i < 5; i++){
        int data;
        cin >> data;
        if(data % 10 == N) Answer++;
    }
    cout << Answer << '\n';
}