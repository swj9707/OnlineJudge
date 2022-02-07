#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    string data;
    cin >> data;
    int answer = 987654321;

    int seq = 0;
    int count = 0;
    for(int i = 0; i < data.length(); i++){
        if(data[i] == 'R') seq = 1;
        if(seq == 1 && data[i] == 'B') count++; 
    }
    answer = min(answer, count);

    seq = 0;
    count = 0;
    for(int i = 0; i < data.length(); i++){
        if(data[i] == 'B') seq = 1;
        if(seq == 1 && data[i] == 'R') count++; 
    }
    answer = min(answer, count);

    seq = 0;
    count = 0;
    for(int i = data.length() - 1; i >= 0; i--){
        if(data[i] == 'R') seq = 1;
        if(seq == 1 && data[i] == 'B') count++; 
    }
    answer = min(answer, count);

    seq = 0;
    count = 0;
    for(int i = data.length() - 1; i >= 0; i--){
        if(data[i] == 'B') seq = 1;
        if(seq == 1 && data[i] == 'R') count++; 
    }
    answer = min(answer, count);

    cout << answer << '\n';
}