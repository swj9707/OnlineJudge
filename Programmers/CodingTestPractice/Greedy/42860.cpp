#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string name) {
    int answer = 0;
    for(int i = 0; i < name.size(); i++){

        cout << name[i] << " " << int(name[i]) - 65 << " ";
    }
    cout << '\n';
    return answer;
}

int main(){
    cout << solution("JEROEN") << '\n';
    cout << solution("JAN") << '\n';
}