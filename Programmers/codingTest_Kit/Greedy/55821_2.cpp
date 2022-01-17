#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve){
    unordered_set<int> l(lost.begin(), lost.end());
    set<int> r;
    unordered_set<int> inter;
    for(auto & x : reserve){
        if(l.find(x) == l.end()) r.insert(x);
        else inter.insert(x);
    }
    for(auto & x : inter) l.erase(x);
    for(auto & x : r){
        if(l.find(x - 1) != l.end()) l.erase(x-1);
        else if(l.find(x+1) != l.end()) l.erase(x+1);
    }
    return n - l.size();
}