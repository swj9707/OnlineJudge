#include <iostream>

using namespace std;

int N;
int competitor1, competitor2;

int getRound(void){

    int round = 1;

    while (N){
        if ((competitor1 + 1) / 2 == (competitor2 + 1) / 2)
            break;
        competitor1 = (competitor1 + 1) / 2;
        competitor2 = (competitor2 + 1) / 2;
        round += 1;
        N /= 2;
    }

    if (!N)
        return -1;
    return round;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cin >> competitor1 >> competitor2;
    cout << getRound() << endl;
}