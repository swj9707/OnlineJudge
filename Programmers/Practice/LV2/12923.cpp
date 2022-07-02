#include <string>
#include <vector>
#include <iostream>
#define MAX 1000000001
using namespace std;

vector<int> vec(MAX);

void init(){
    for(int i = 1; i <= 10000000; i++){
        int mul = 1;
        while(i * mul <= MAX){
            vec[i*mul] = i;
            mul++;
        }
    }
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    init();
    for(int i = 1; i <= 10; i++){
        cout << vec[i] << " ";
    } 
    cout << '\n';
    return answer;
}

int main(){
    solution()
}