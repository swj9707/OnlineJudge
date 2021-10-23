#include <iostream>

using namespace std;

int main(){
    int L, P, V;
    int Case = 1;
    while(true){
        cin >> L >> P >> V;
        if(L == 0 && P == 0 && V == 0) break;
        int Answer = (V/P)*L + min(V%P, L);
        cout << "Case " << Case << ": " << Answer << "\n";
        Case++;
    }
}