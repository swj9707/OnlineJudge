#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

unordered_map<string, string> nickNameMap;
vector<pair<string, string>> recordVector;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    for(auto i : record){
        stringstream ss; 
        ss << i;
        string query, userId, nickName;
        ss >> query >> userId;
        if(query == "Enter" || query == "Change"){
            ss >> nickName;
            nickNameMap[userid] = nickName;
        } 
        recordVector.push_back({query, userId});
    }

    for(auto i : recordVector){
        string tmp;
        if(i.first == "Enter"){
            tmp = nickNameMap[i.second] + "님이 들어왔습니다."
        } else if (i.first == "Leave"){
            tmp = nickNameMap[i.second] + "님이 나갔습니다."
        }
        answer.push_back(tmp);
    }
    return answer;
}