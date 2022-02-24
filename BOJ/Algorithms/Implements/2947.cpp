#include <iostream>

using namespace std;

void swap(int *A, int *B){
    int tmp = *A;
    *A = *B;
    *B = tmp;
}

void printData(int *Arr){
    for(int i = 0; i < 5; i++) cout << Arr[i] << " ";
    cout << '\n';
}

bool CheckData(int *Arr){
    int Ans[5] = {1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i++){
        if(Ans[i] != Arr[i]) return false;
    }
    return true;
}

int main(){
    int Arr[5];
    for(int i = 0; i < 5; i++) cin >> Arr[i];

    while(1){
        if(Arr[0] > Arr[1]) {
            swap(&Arr[0], &Arr[1]);
            printData(Arr);
        }
        if(Arr[1] > Arr[2]) {
            swap(&Arr[1], &Arr[2]);
            printData(Arr);
        }
        if(Arr[2] > Arr[3]){
            swap(&Arr[2], &Arr[3]);
            printData(Arr);
        }
        if(Arr[3] > Arr[4]) {
            swap(&Arr[3], &Arr[4]);
            printData(Arr);
        }
        if(CheckData(Arr)) break;
    }
}