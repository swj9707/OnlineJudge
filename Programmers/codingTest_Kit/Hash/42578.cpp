#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> uom;
    for(auto i : clothes) uom[i[1]]++;
    for(auto i : uom) answer *= (i.second + 1);
    return answer-1;
}