#include <string>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    string English[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    for(int i = 0 ; i < 10; i++){
        if(s.find(English[i]) != s.end())
        cout << s.find(English[i]) << '\n';
    }
    return answer;
}