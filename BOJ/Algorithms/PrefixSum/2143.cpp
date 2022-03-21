#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long T;
    int N, M;
    vector<long long> A, B;
    vector<long long> ASum, BSum;
    long long tmp, sum, result =0;
    cin >> T;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> tmp;
        A.push_back(tmp);
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> tmp;
        B.push_back(tmp);
    }
    for(int i = 0; i < N; i++){
        sum = A[i];
        ASum.push_back(sum);
        for(int j = i + 1; j < N; j++){
            sum += A[j];
            ASum.push_back(sum);
        }
    }
    for(int i = 0; i < M; i++){
        sum = B[i];
        BSum.push_back(sum);
        for(int j = i + 1; j < M; j++){
            sum += B[j];
            BSum.push_back(sum);
        }
    }
    sort(ASum.begin(), ASum.end());
    sort(BSum.begin(), BSum.end());
    for (int i = 0; i < ASum.size(); i++){
        int low = lower_bound(BSum.begin(), BSum.end(), T - ASum[i]) - BSum.begin();
        int high = upper_bound(BSum.begin(), BSum.end(), T - ASum[i]) - BSum.begin();
        result += high - low;
    }
    cout << result << "\n";
}