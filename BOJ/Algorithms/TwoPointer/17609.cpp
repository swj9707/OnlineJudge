#include <iostream>

using namespace std;

int isPalindrome(int left, int right, int del, string tmp){
    while(left < right){
        if(tmp[left] != tmp[right]){
            if(del == 1){
                if(isPalindrome(left+1, right, 0, tmp) == 0 || isPalindrome(left, right-1, 0, tmp) == 0) return 1;
                return 2;
            }
            else return 2;
        }
        else{
            left++; right--;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    while(N--){
        string tmp; cin >> tmp;
        int answer = isPalindrome(0, tmp.length()-1, 1, tmp);
        cout << answer << '\n';
    }
}