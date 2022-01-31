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
    unordered_map<string, unordered_map<int, int>> musicList;
    unordered_map<string, int> music;
    int N = genres.size();
    for(int i = 0 ; i < N; i++) {
        musicList[genres[i]][i] = plays[i];
        music[genres[i]] += plays[i];
    }
    while(music.size()){
        string genre;
        int max = 0;
        for(auto mu : music){
            if(max < mu.second){
                max = mu.second;
                genre = mu.first;
            }
        }
        for(int i = 0; i < 2; i++){
            int max = 0, index = -1;
            for(auto data : musicList[genre]){
                if(max < data.second){
                    max = data.second;
                    index = data.first;
                }
            }
            if(index != -1){
                answer.push_back(index);
                musicList[genre].erase(index);
            }
            else break;
        }
        music.erase(genre);
    }
    return answer;
}

int main(){
    solution({"classic", "pop", "classic", "classic", "pop"},{500, 600, 150, 800, 2500});
}