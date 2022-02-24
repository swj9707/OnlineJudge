#include <iostream>
#include <time.h>
using namespace std;

int main(){
    string tmp;
    cin >> tmp;
    srand(time(NULL));
    int randNum = rand() % 2 + 1;
    if(randNum % 2 == 0) cout << 0 << '\n';
    else cout << 1 << '\n';
}