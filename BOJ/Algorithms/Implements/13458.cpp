#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(int A, int B){
    return A > B;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long answer = 0;
    int N, B, C;
    // B -> 총감독 , C -> 부감독
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    cin >> B >> C;
    for(auto i : A){
        if(i - B <= 0) answer += 1;
        else{
            answer += 1;//총감독관 아저씨
            int amount = i - B;
            int div = (i - B) / C;
            int reminder = (i - B) % C;
            if(div == 0 && reminder != 0) answer += 1;
            else if(div != 0 && reminder == 0) answer += div;
            else answer += div + 1;
        }
    }

    cout << answer << '\n';
}