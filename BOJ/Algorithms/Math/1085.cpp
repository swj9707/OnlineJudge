#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    int tmp1, tmp2;
    tmp1 = min(x, y);
    tmp2 = min(w - x, h - y);
    cout << min(tmp1, tmp2) << '\n';
}