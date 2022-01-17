#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    string str = "";
    unordered_map<string, int> d;
    
    for(auto& i : phone_book){
        str = "";
        for(int j=0; j<i.size(); j++){
            str += i[j];
            d[str]++;
        }
    }
    
    for(auto& i : phone_book){
        if(d[i] > 1){
            answer = false;
            break;
        }
    }
    return answer;
}