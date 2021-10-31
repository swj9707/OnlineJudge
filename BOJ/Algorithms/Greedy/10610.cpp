#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//끝자리의 수가 0이며 각 자리의 수의 합이 3의 배수
int main(){
    string N;
    cin >> N;
    vector<int> data;
    for(int i = 0; i < N.size(); i++){
        int inputData = N[i] - '0';
        data.push_back(inputData);
    }
    sort(data.begin(), data.end());
    if(data[0] != 0) {cout << "-1\n"; return 0;}
    else{
        int sum = 0;
        for(int i = 1; i < data.size(); i++){
            sum += data[i];
        }
        if(sum % 3 != 0) {cout << "-1\n"; return 0;}
        else{
            string answer = "";
            for(int i = data.size() - 1; i >= 1; i--) {
                answer += (char)(data[i]+48);
            }
            answer += "0";
            cout << answer << '\n';
            return 0;
        }
    }
}