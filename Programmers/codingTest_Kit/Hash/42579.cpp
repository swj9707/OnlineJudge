#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, vector<pair<int, int>>> uom;
    int N = genres.size();
    for(int i = 0 ; i < N; i++){
        uom[genres[i]].push_back({plays[i], i});
    }
    
    return answer;
}

int main(){
    solution({"classic", "pop", "classic", "classic", "pop"},{500, 600, 150, 800, 2500});
}