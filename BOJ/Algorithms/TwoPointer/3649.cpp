#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int dst, N;
    while(cin >> dst >> N){
        vector<int> vec;
        for(int i = 0; i < N; i++){
            int input; cin >> input;
            vec.push_back(input);
        }
        sort(vec.begin(), vec.end());

        dst = dst * 10000000;
        int left = 0, right = vec.size() - 1;
        int leftAns = -1, rightAns = -1;
        while(left < right){
            int sum = vec[left] + vec[right];
            if(sum == dst){
                leftAns = vec[left];
                rightAns = vec[right];
                break;
            }
            else if (sum < dst){
                left++;
            }
            else {
                right--;
            }
        }
        
        if(leftAns == -1 || rightAns == -1) cout << "danger\n";
        else cout << "yes " << leftAns << " " << rightAns << '\n';
    }
}