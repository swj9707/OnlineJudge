#include <iostream>
#include <string>

using namespace std;

int main(){
    string data;
    int Num[] = {3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,9,9,9,10,10,10,10};
    int answer = 0;
    cin >> data;
    for(int i = 0; i < data.size(); i++){
        answer += Num[int(data[i]) - 'A'];
    }
    cout << answer;
}