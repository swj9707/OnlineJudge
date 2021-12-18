#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printData(T a){
    for(auto i : a){
        cout << i << " ";
    }
    cout << '\n';
}

int main()
{
    int T;
    cin >> T;
    for (int caseNum = 1; caseNum <= T; caseNum++)
    {
        int answer = 0;
        int N;
        cin >> N;
        int *Map;
        Map = (int *)malloc(sizeof(int) * N);
        for (int i = 0; i < N; i++) cin >> Map[i];
        vector<vector<int>> routeData;
        for(int i = 0; i < N; i++){
            int dest = -1;
            int k;
            if(i + 15 < N) k = i + 15;
            else k = N - 1;
            for(int j = k; j > i; j--){
                if(Map[j] == 3){
                    dest = j;
                    break;
                }
            }
            if(dest == -1) break;
            vector<int> tmp;
            for(int j = i; j <= dest; j++) tmp.push_back(Map[j]);
            routeData.push_back(tmp);
            i = dest -1;
        }

        //for(auto i : routeData) printData(i);

        for(auto route : routeData){
            //마지막 인덱스 = 목적지
            int N = route.size();
            int time = 0;
            for(int i = 0; i < N;){
                cout << "i : " << i << '\n';
                if(i + 6 < N){
                    int j;
                    for(j = 6; j >= 1; j--){
                        if(route[i + j] == 2){
                            time += j + 1;
                            i = i + j;
                            break;
                        }
                        else if(route[i + j] == 3){
                            time += j;
                            if(time <= 15){
                                answer += time;
                                i = i + j;
                                time = 0;
                            }
                            else{
                                answer = -1;
                                i = N;
                            }
                            break;
                        }
                    }
                    if(j == 0){
                        answer = -1;
                        break;
                    }
                }
                else{//그냥 쭉 가면됨
                    time += N - i -1;
                    answer += time;
                    break;
                }
            }
            if(answer == -1) break;
            //cout << answer << '\n';
        }

        cout << "#" << caseNum << " " << answer << '\n';
        free(Map);
    }
}