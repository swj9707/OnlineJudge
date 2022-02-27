#include <iostream>
#include <unordered_set>
using namespace std;

int Arr[5001];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    for(int i = 1; i <= N; i++) cin >> Arr[i];
    unordered_set<int> UOS;
    for(int i = 1; i < N; i++){
        int delta = Arr[i+1] - Arr[i];
        UOS.insert(delta);
    }
    cout << UOS.size() << '\n';
}