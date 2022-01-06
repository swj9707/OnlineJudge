#include <iostream>
using namespace std;

const int MAX = 1e6;

string P;
bool Visit[MAX];
bool check(int num){
    int sum = 0;
    for(int i = 0; P[i]; i++) sum = (sum * 10 + (P[i]-'0')) % num;
    if(sum == 0) return true;
    else return false;
}

int main(){
    long long P;
    int K;
    bool good = true;
    int answer = 0;
    cin >> P >> K;
    for(int i = 2; i < K; i++){
        if(Visit[i]) continue;
        if(check(i)){
            good = false;
            answer = i;
            break;
        }
        for(int j = 2*i; j < K; j += i) Visit[j] = true;
    }
    if(good) cout << "GOOD" << '\n';
    else cout << "BAD " << answer << '\n';
}