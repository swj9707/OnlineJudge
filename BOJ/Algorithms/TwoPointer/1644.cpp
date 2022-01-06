#include <iostream>
#define MAX 4000001
using namespace std;

bool Visit[MAX];
int Prime[MAX];

int main(){
    int N, primeCnt = 0;
    cin >> N;
    for(int i = 2; i <= N; i++){
        if(Visit[i]) continue;
        Prime[primeCnt++] = i;
        for(long long j = (long long)i*i; j <= N; j += i) Visit[j] = true;
        //i의 배수를 전부 날려버림
    }
    int left = 0, right = 0, count = 0, sum = 0;
    while(1){
        if(sum >= N) sum -= Prime[left++];
        else if(right == primeCnt) break;
        else sum += Prime[right++];

        if(sum == N) count++;
    }
    cout << count << '\n';
}