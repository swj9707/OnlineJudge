#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    while(N--){
        string tmp; cin >> tmp;
        int left = 0, right = tmp.length() - 1;
        int answer = 0, count = 0;
        while(left < right){
            if(tmp[left] == tmp[right]) count++;
            left++; right--;
        }
        int halfLength = tmp.length() / 2;
        if(halfLength == count) answer = 0;
        else if(halfLength == count + 1) answer = 1;
    }
}