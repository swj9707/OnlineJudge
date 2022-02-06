#include <string>
#include <vector>
#include <string>
using namespace std;

string mkBinary(int X, int n){
    string result(n, 0);
    for(int i = 0; i < n; i++){
        if (X % 2 == 1){
            result[n - i - 1] += '1';
        }
        else result[n - i - 1] += '0';
        X /= 2;
    }
    return result;
}

string mkResult(int A, int B, int n){
    string strA = mkBinary(A, n);
    string strB = mkBinary(B, n);
    string result(n, 0);
    for(int i = 0; i < n; i++){
        if(strA[i] != strB[i]) result[i] = '#';
        else {
            if(strA[i] == '0') result[i] = ' ';
            else result[i] = '#';
        }
    }
    return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i = 0; i < n; i++){
        answer.push_back(mkResult(arr1[i], arr2[i], n));
    }
    return answer;
}