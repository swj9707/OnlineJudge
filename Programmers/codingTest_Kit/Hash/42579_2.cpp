#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool comp(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

bool compMusic(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> music;
    unordered_map<string, vector<pair<int, int>>> musicData;
    int N = genres.size();
    for(int i = 0; i < N; i++){
        music[genres[i]] += plays[i];
        musicData[genres[i]].push_back({plays[i], i});
    }
    vector<pair<string, int>> musicVector;
    musicVector.assign(music.begin(), music.end());
    sort(musicVector.begin(), musicVector.end(), comp);

    for(int i = 0; i < musicVector.size(); i++){
        string genre = musicVector[i].first;
        sort(musicData[genre].begin(), musicData[genre].end(), compMusic);
        for(int j = 0; (j < musicData[genre].size()) && (j < 2) ; j++){
            answer.push_back(musicData[genre][j].second);
        }
    }
    return answer;
}