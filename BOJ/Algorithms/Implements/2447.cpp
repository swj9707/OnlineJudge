#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void star(int i,int j,int n){
    if ((i/n)%3==1 && (j/n)%3==1) cout << " ";
    else if(n/3==0) cout << "*";
    else star(i,j,n/3);
}
int main(){
    int N,i,j;
    cin >> N;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++) star(i,j,N);
        cout << '\n';
    }
}