#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int N;
        cin >> N;
        int Data[20];
        for(int j = 0; j < N; j++) cin >> Data[j];
        int maxNum = -99999, minNum = 99999;
        for(int j = 0; j < N; j++){
            maxNum = max(maxNum, Data[j]);
            minNum = min(minNum, Data[j]);
        }
        int Answer = 0;
        for (int j = 1; j <= N-2; j++){
            if(Data[j] != maxNum && Data[j] != minNum) Answer++;
        }
        cout << "#" << i+1 << " " << Answer << "\n";
    }
}