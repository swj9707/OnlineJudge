#include <iostream>
#include <algorithm>
#define MAX 200001
using namespace std;

int N, H;
int Arr1[100001];
int Arr2[100001];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> H;
    for(int i = 0; i < N / 2; i++) cin >> Arr1[i] >> Arr2[i];
    sort(Arr1, Arr1 + (N / 2));
    sort(Arr2, Arr2 + (N / 2));
    int l = 0, r = H;
    int result = MAX;
    int answer = 0;
    for(int i = 1; i <= H; i++){
        int val = lower_bound(Arr1, Arr1 + (N / 2), i) - Arr1;
        val += upper_bound(Arr2, Arr2 + (N / 2), H - i) - Arr2;
        val = N - val;

        if(result == val) answer++;
        else if(result > val){
            result = val;
            answer = 1;
        }
    }
    cout << result << " " << answer << '\n';
}