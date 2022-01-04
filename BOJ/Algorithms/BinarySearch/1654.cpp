#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;

bool check(unsigned int length, unsigned int value){
    unsigned int sum = 0;
    if(length == 0) return false;
    for(int i = 0; i < vec.size(); i++) sum += vec[i] / length;
    if(sum >= value) return true;
    else return false;
}

int main(){
    unsigned int K, N;
    cin >> K >> N;
    unsigned int maxValue = 0;
    for(int i = 0; i < K; i++){
        unsigned int tmp;
        cin >> tmp;
        vec.push_back(tmp);
        maxValue = max(maxValue, tmp);
    }
    unsigned int left = 0, right = maxValue;
    unsigned int result = 0;
    while(left <= right){
        unsigned int mid = (left + right) / 2;
        if(check(mid, N)) {
            result = max(result, mid);
            left = mid + 1;
        }
        else right = mid - 1;
    }
    cout << result << '\n';
}