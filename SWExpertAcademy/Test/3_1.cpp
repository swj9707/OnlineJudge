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
        int time = 0;//한 시퀸스 당 걸린 시간
        //주의! 불가능한 경우도 있다
        for(int i = 0; i < N; i++){
            //i -> 현재 위치
            if(i + 6 < N){
                for(int j = 6; j > 0; j--){
                    if(mapData[i + j] == 2){//캠핑장이라면?
                        time += j + 1;//한시간 쉬었다 치고
                        i = j;//새로운 위치 갱신
                        break;
                    }
                    else if(mapData[i + j] == 3){
                        time + j;
                        if(time <= 15){
                            
                        }
                    }
                }
            }
            else{//이제 거의 다온 상황 -> 휴계소가 있다고 해도 갈 이유가 있는가?
                time = N - i - 1;
                break;
            }
        }
        cout << "#" << caseNum << " " << answer <<'\n';
    }
}