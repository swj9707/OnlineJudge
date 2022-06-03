#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> order;
vector<int> plug;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, K;
    int answer = 0;
    cin >> N >> K;
    for(int i = 0; i < K; i++){
        int input; cin >> input;
        order.push_back(input);
    }
    for(int i = 0; i < K; i++){
        if(plug.size() < N) {
            if(plug.size() == 0) plug.push_back(order[i]);
            else{
                if(find(plug.begin(), plug.end(), order[i]) == plug.end()){
                    plug.push_back(order[i]);
                }
            }
        } else {
            if(find(plug.begin(), plug.end(), order[i]) == plug.end()){
                int index = -1;
                int last = -1;
                for(int j = 0; j < N; j++){
                    int tmp = 0;
                    for(int t = i + 1; t < K; t++){
                        if(order[t] == plug[j]) break;
                        tmp++;
                    }
                    if(last < tmp){
                        last = tmp;
                        index = j;
                    }
                }
                plug[index] = order[i];
                answer++;
            }
        }
    }
    cout << answer << '\n';
}