#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

void DFS(string str, int now, int depth, vector<char> vec, int L, int C){
    if(depth == L){
        int a = 0, b= 0;
        for(int i = 0; i < str.length(); i++){
            if(str[i] == 'a' || str[i] == 'i' || str[i] == 'e' || str[i] == 'o' || str[i] == 'u'){
                a++;
            }
            else b++;
        }
        
        if(a >= 1 && b >= 2){
            cout << str << '\n';
        }
        return;
    }
    for(int i = now + 1; i <= C - L + depth; i++){
        DFS(str+vec[i], i, depth+1, vec, L, C);
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int L, C; cin >> L >> C;
    vector<char> vec;
    for(int i = 0; i < C; i++){
        char inputChar;
        cin >> inputChar;
        vec.push_back(inputChar);
    }

    sort(vec.begin(), vec.end());

    string s = "";
    for(int i = 0; i <= C - L; i++){
        DFS(s+vec[i],i,1, vec, L, C);
    }
}