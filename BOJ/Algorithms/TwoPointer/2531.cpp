#include <iostream>
#include <cstring>
using namespace std;
int convey[30001];
int check[3001];
int answer = 0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, d, k, c;
    int answer = 0;
    cin >> N >> d >> k >> c;
    for(int i = 0; i < N; i++) cin >> convey[i];
    int left = 0;
    while(left != N){
        int dub = 0;
        int coupon = 1;
        for(int i = left; i < left + k; i++){
            if(check[convey[i % N]] == 0) check[convey[i % N]] = 1;
            else dub++;
            if(convey[i % N] == c) coupon = 0;
        }
        answer = max(answer, k - dub + coupon);
        left++;
        memset(check, 0, sizeof(check));
    }
    cout << answer << '\n';
}