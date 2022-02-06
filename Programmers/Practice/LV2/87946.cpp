#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    do{
        for(auto i : dungeons){
            cout << i[0] << i[1] << '\n';
        }
        
    }while(next_permutation(dungeons.begin(), dungeons.end()));
    
    return answer;
}