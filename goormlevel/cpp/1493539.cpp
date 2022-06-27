#include <iostream>
#define MAX 1000001
using namespace std;

int game[MAX];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    for(int i = 1; i <= T; i++) {
        cin >> game[i];
    }
    int a = 0, b = 0;
    for(int i = 1 ; i <= T; i++){
        int countOf = game[i];
        int count = 0;
        if(countOf > 3){
            count += (countOf / 3) + (countOf % 3);
        } else {
            count += countOf;
        }

        if(count % 2 == 0) b += 1;
        else a += 1;
    }
    if(a == b) cout << "tie\n";
    else cout << max(a, b) << '\n';

}