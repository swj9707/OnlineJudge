#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;

bool check(int result, int value){
    int sum = 0;
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] >= result) sum += result;
        else sum += vec[i];
    }
    if(sum <= value) return true;
    else return false;
}

int main(){
    int N, M;
    cin >> N;
    int maxValue = 0;
    for(int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
        maxValue = max(maxValue, tmp);
    }
    cin >> M;
    int left = 0, right = maxValue;
    int answer = 0;
    while(left <= right){
        int mid = (left + right) / 2;
        if(check(mid, M)){
            answer = max(answer, mid);
            left = mid + 1;
        }
        else right = mid - 1;
    }
    cout << answer << '\n';
}