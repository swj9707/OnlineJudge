#include <iostream>
#define MAX 1004000
using namespace std;

int arr[MAX];

bool isPalindrom(int inputData){
    string str = to_string(inputData);
    for(int i = 0; i < str.size() / 2; i++){
        if(str[i] != str[str.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 1; i <= MAX; i++) arr[i] = i;

    for(int i = 2; i * i <= MAX; i++) {
        if(arr[i] == -1) continue;
        for(int j = i * 2; j <= MAX; j += i){
            arr[j] = -1;
        }
    }
    arr[0] = arr[1] = -1;

    int N; cin >> N;
    for(int i = N; i <= MAX; i++){
        if(arr[i] != -1){
            if(isPalindrom(arr[i])){
                cout << arr[i];
                break;
            }
        }
    }
    return 0;
}