#include <bits/stdc++.h>

using namespace std;

int M;

int cutCake(int cake){
    int result = 0;
    while(cake > 10){
        if(M > 0){
            if(cake - 10 > 0){
                 cake -= 10;
                 result++;
                 M--;
            }
        } else break;
    }
    if(cake == 10) result++;
    return result;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int answer = 0;
    vector<int> vecTen;
    vector<int> vecOther;
    int N; cin >> N >> M;
    for(int i = 0; i < N; i++){
        int tmp; cin >> tmp;
        if(tmp % 10 == 0){
            vecTen.push_back(tmp);
        } else {
            vecOther.push_back(tmp);
        }
    }
    sort(vecTen.begin(), vecTen.end());
    sort(vecOther.begin(), vecOther.end());

    for(int i = 0; i < vecTen.size(); i++){
        if(M != 0){
            if(vecTen[i] > 10){
                answer += cutCake(vecTen[i]);
            } else if (vecTen[i] == 10){
                answer += 1;
            }
        } else break;
    }
    for(int i = 0; i < vecOther.size(); i++){
        if(M != 0){
            if(vecOther[i] > 10){
                answer += cutCake(vecOther[i]);
            } 
        } else break;
    }

    cout << answer << '\n';
    return 0;
}