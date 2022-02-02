#include <iostream>
#include <sstream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string initData;
    cin >> initData;
    int N;
    cin >> N;
    int cursor = initData.length() - 1;
    for(int tc = 0; tc < N; tc++){
        string command;
        getline(cin, command);
        istringstream ss(command);
        char cmd, inputData;
        if(command.length() == 1) ss >> cmd;
        else ss >> cmd >> inputData;
        
    }
}