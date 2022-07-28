#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, k, input;
    vector<ll> nums;

    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> input;
        nums.push_back(input);
    }

    cin >> k;

    k = n / k;

    for(auto it = nums.begin(); it != nums.end();){
        sort(it, it + k);
        it += k;
    }

    for(ll i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
    return 0;
}