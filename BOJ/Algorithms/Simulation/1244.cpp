#include <bits/stdc++.h>

using namespace std;

int switchArray[101];

void swapSwitch(int *a){
    if(*a == 0){
        *a = 1;
    } else {
        *a = 0;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> switchArray[i];
    }
    int T; cin >> T;
    while(T--){
        int mf, num;
        cin >> mf >> num;
        if(mf == 1){
            for(int i = num; i <= N; i += num){
                switchArray[i] = !switchArray[i];
            }
        } else {
            int left = num - 1;
            int right = num + 1;
            switchArray[num] = !switchArray[num];
            while(left >= 1 && right <= N){
                if(switchArray[left] != switchArray[right]){
                    break;
                }
                switchArray[left] = !switchArray[left];
                switchArray[right] = !switchArray[right];
                left--;
                right++;
            }

        }
    }
    for(int i = 1; i <= N; i++){
        cout << switchArray[i] << " ";
        if(i % 20 == 0) cout << '\n';
    }
} 