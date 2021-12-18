#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printVector(T vec){
    for(auto a : vec){
        std::cout << a <<" ";
    }
    std::cout << '\n';
}

int main(){
    int T;
    cin >> T;
    for(int caseNum = 1; caseNum <= T; caseNum++){
        int answer = 0;
        int N;
        cin >> N;
        vector<int> mapData(N);
        for(int i = 0; i < N; i++) cin >> mapData[i];
        for(int i = N - 1; i >= 0; i--){
            if(mapData[i] == 3) break;
            else {
                mapData.pop_back();
                N--;
            }
        }
        for(int i = 0; i < N; i++){
            //i -> 현재 위치
            if(i + 6 < N){
                for(int j = i + 6; j > 0; j--){
                    if(mapData[j] == 2){//캠핑장이라면?
                        answer += j + 1;//한시간 쉬었다 치고
                        i = j;//새로운 위치 갱신
                        break;
                    }
                    else if(mapData[j] == 3){

                    }
                }
            }
            else{//이제 거의 다온 상황
                for(int j = i; j < N; j++){
                    
                }

            }
        }

        cout << "#" << caseNum << " " << answer <<'\n';
    }
}