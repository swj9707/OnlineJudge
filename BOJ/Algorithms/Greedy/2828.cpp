#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    int J;
    cin >> J;
    int answer = 0;
    int left = 1, right = M;
    while(J--){
        int X;
        cin >> X;
        bool flag = true;
        while(flag){
            if(left <= X && X <= right){
                flag = false;
            }
            else if(left > X){
                left--;
                right--;
                answer++;
            }
            else{
                left++;
                right++;
                answer++;
            }
        }
    }
    cout << answer << '\n';
}