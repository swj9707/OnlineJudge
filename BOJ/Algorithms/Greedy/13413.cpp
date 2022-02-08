#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int N;
        string src;
        string dst;
        int WCount = 0;
        int BCount = 0;
        cin >> N >> src >> dst;
        for(int i = 0; i < N; i++){
            if(src.at(i) != dst.at(i)){
                if(src.at(i) == 'B') BCount++;
                else WCount++;
            }
        }
        if(BCount < WCount) cout << WCount << '\n';
        else cout << BCount << '\n';
    }  
}