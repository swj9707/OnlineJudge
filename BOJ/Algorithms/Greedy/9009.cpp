#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; cin >> T;
    int Fibo[46] = {1, 2};
    for(int i = 2; i < 46; i++){
        Fibo[i] = Fibo[i - 1] + Fibo[i - 2];
        cout << Fibo[i] << '\n';
    }

    while(T--){
        int N; cin >> N;
        vector<int> Answer;
        for(int i = 45; i >= 1; i--){
            if(Fibo[i] <= N){
                Answer.push_back(Fibo[i]);
                N -= Fibo[i];
            }
        }
        sort(Answer.begin(), Answer.end());
        for(int i = 0; i < Answer.size(); i++){
            cout << Answer[i] <<  " ";
        }    
        cout << '\n';


    }

}