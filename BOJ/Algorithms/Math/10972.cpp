#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin>>a[i];
    if (next_permutation(a.begin(), a.end())) {
        for (int i = 0; i < n; i++) cout << a[i]<<" ";
    }
    else cout << "-1";
}