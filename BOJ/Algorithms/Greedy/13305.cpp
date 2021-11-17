#include <iostream>
#include <algorithm>
#define MAX 1000000000
using namespace std;
//거리 : 1 ~ MAX, 가격 : 1 ~ MAX

long long dist[100001];
long long price[100001];

int main(){
    int N;
    cin >> N;
    for(int i = 1 ; i <= N - 1 ; i++) cin >> dist[i];
    for(int i = 1 ; i <= N ; i++) cin >> price[i];

    long long maxValue = MAX;
    long long sum = 0;

    for(int i = 1 ; i <= N - 1; i++){
        if(price[i] < maxValue) maxValue = price[i];
        sum += maxValue * dist[i];
    }
    cout << sum << '\n';
}