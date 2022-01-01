#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        int N;
        cin >> N;
        int Answer = 0;
        vector<int> vec(N);
        for (int j = 0; j < N; j++)
        {
            cin >> vec[j];
        }
        sort(vec.begin(), vec.end());
        deque<int> odd;
        deque<int> even;
        for (int j = 0; j < N; j++)
        {
            if (vec[j] % 2 == 0)
                even.push_back(vec[j]);
            else
                odd.push_back(vec[j]);
        } //전체 vector에서 홀수 짝수를 구분해서 각 vector에 저장
        //어차피 정렬 된 상태라 두 vector모두 정렬 된 상황
        while (!vec.empty())
        {
            int FirstNum = vec.back();
            int SecondNum = -9999;
            vec.pop_back();
            //정렬했으니까 가장 큰놈을 일단 저장
            bool isOdd = true;
            if (FirstNum % 2 == 0)
                isOdd = false;
            if (isOdd)
            { //홀수일 때 -> 홀수 + 홀수 = 짝수
                //odd.erase(remove(odd.begin(), odd.end(), FirstNum), odd.end());
                odd.pop_back();
                if (!odd.empty())
                { //홀수가 존재한다면 홀수중에서 가장 작은놈
                    SecondNum = odd.front();
                    //odd.erase(remove(odd.begin(), odd.end(), SecondNum), odd.end());
                    odd.pop_front();
                    Answer += max(SecondNum, FirstNum);
                }
                else
                { //홀수가 더이상 없다? 짝수중에 제일 큰놈을 집어서 어쨌든 남은 놈 중 큰놈 가져가게 하기
                    SecondNum = even.back();
                    even.pop_back();
                    Answer += min(SecondNum, FirstNum);
                }
            }
            else
            { //짝수일 때 -> 짝수 + 짝수 = 짝수
                even.pop_back();
                if (!even.empty())
                { //짝수가 존재한다면 짝수중에서 가장 작은놈
                    SecondNum = even.front();
                    even.pop_front();
                    Answer += max(SecondNum, FirstNum);
                }
                else
                { //짝수가 더이상 없다? 홀수중에 제일 큰놈을 집어서 어쨌든 남은 놈 중 큰놈 가져가게 하기
                    SecondNum = odd.back();
                    odd.pop_back();
                    Answer += min(SecondNum, FirstNum);
                }
            }
            auto it = find(vec.begin(), vec.end(), SecondNum);
            vec.erase(it);
        }
        cout << "#" << i << " " << Answer << '\n';
    }
    return 0;
}