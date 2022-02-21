#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string inputString;
    cin >> inputString;
    int countZero = 0, countOne = 0;
    for(auto i : inputString){
        if(i == '0') countZero++;
        else countOne++;
    }
    int dstZero = countZero / 2;
    int dstOne = countOne / 2;
    while(countZero != dstZero){
        int idx = inputString.rfind('0');
        if(idx != string::npos){
            inputString.erase(idx,1);
            countZero--;
        }
    }
    while(countOne != dstOne){
        int idx = inputString.find('1');
        if(idx != string::npos){
            inputString.erase(idx,1);
            countOne--;
        }
    }
    cout << inputString << '\n';
}