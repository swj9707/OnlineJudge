#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string A, B;
    cin >> A >> B;
    int A_size = A.size();
    int B_size = B.size();
    for(int i = 0; i < A_size; i++){
        if(A[i] == '6') A[i] = '5';
    }
    for(int i = 0; i < B_size; i++){
        if(B[i] == '6') B[i] = '5';
    }
    cout << stoi(A) + stoi(B) << ' ';
        for(int i = 0; i < A_size; i++){
        if(A[i] == '5') A[i] = '6';
    }
    for(int i = 0; i < B_size; i++){
        if(B[i] == '5') B[i] = '6';
    }
    cout << stoi(A) + stoi(B) << '\n';   
}