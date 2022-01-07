#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> vec(N);
    set<string> st;
    for(int i = 1; i <= N; i++) vec[i - 1] = i;
    do{
        string tmp = "";
        for(int i = 0; i < M; i++){
            tmp += to_string(vec[i]) + " ";
        }
        st.insert(tmp);
    } while(next_permutation(vec.begin(), vec.end()));
    for(auto i : st){
        cout << i << '\n';
    }
    return 0;
}