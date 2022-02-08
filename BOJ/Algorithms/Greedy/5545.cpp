#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, A, B, C;
    cin >> N >> A >> B >> C;
    vector<int> topping(N);
    for(int i = 0; i < N; i++) cin >> topping[i];
    sort(topping.begin(), topping.end(), greater<int>());

    int sumOfcal = C;
    double answer = C / A;

    for(int i = 0; i < N; i++){
        sumOfcal += topping[i];
        int amount = A + B * (i+1);
        double cal_per_amount = (double)sumOfcal / (double)amount;
        answer = max(answer, cal_per_amount);
    }
    cout << floor(answer) << '\n';
}