#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    unordered_set<int> reserveSet(reserve.begin(), reserve.end());
    unordered_set<int> lostSet(lost.begin(), lost.end());
    for(auto & X : lostSet){
        if(reserveSet.find(X)!= reserveSet.end()){
            reserveSet.erase(X);
        }
    }
    for(auto & X : reserveSet){
        if(lostSet.find(X) != lostSet.end()){
            lostSet.erase(X);
        }
    }
    for(auto & X : reserveSet){
        if(lostSet.find(X-1) != lostSet.end()){
            lostSet.erase(X-1);
        }
        else if(lostSet.find(X+1) != lostSet.end()){
            lostSet.erase(X+1);
        }
    }
    
    return n - lostSet.size();
}