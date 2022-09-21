#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int answer = 0;
    int B, C, D;
    cin >> B >> C >> D;
    int maximumSetMenu = min(min(B, C), D);
    vector<int> burger(B);
    vector<int> side(C);
    vector<int> drink(D);
    for(int i = 0; i < B; i++){
        cin >> burger[i];
    }
    for(int i = 0; i < C; i++){
        cin >> side[i];
    }
    for(int i = 0; i < D; i++){
        cin >> drink[i];
    }
    int allAmount = accumulate(burger.begin(), burger.end(), 0)
        + accumulate(side.begin(), side.end(), 0) + accumulate(drink.begin(), drink.end(), 0);

    sort(burger.begin(), burger.end(), greater<int>());
    sort(side.begin(), side.end(), greater<int>());
    sort(drink.begin(), drink.end(), greater<int>());
    for(int i = 0; i < maximumSetMenu; i++){
        answer += (burger[i] + side[i] + drink[i]) * 0.9;
    }
    if(B > maximumSetMenu){
        answer += accumulate(burger.begin() + maximumSetMenu, burger.end(), 0);
    }
    if(C > maximumSetMenu){
        answer += accumulate(side.begin() + maximumSetMenu, side.end(), 0);
    }
    if(D > maximumSetMenu){
        answer += accumulate(drink.begin() + maximumSetMenu, drink.end(), 0);
    }
    cout << allAmount << '\n';
    cout << answer << '\n';
}