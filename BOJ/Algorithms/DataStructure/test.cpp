#include <iostream>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin >> N;
    set<int> st;
    for(int i = 0; i < N; i++){
        int x; cin >> x;
        st.insert(x);
    }
    if(st.size() >= 3){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
    return 0;
}