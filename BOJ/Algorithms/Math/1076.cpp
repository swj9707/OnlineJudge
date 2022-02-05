#include <iostream>
#include <cmath>
using namespace std;

int getResult(string tmp){
    if(tmp == "black") return 0;
    else if(tmp == "brown") return 1;
    else if(tmp == "red") return 2;
    else if(tmp == "orange") return 3;
    else if(tmp == "yellow") return 4;
    else if(tmp == "green") return 5;
    else if(tmp == "blue") return 6;
    else if(tmp == "violet") return 7;
    else if(tmp == "grey") return 8;
    else if(tmp == "white") return 9;
    else return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int result[3];
    for(int i = 0; i < 3; i++){
        string tmp;
        cin >> tmp;
        result[i] = getResult(tmp);
    }
    long long answer = result[0]*10 + result[1];
    int mult = 1;
    for(int i = 0; i < result[2]; i++) mult *= 10;
    answer *= mult;
    cout << answer << '\n';
}