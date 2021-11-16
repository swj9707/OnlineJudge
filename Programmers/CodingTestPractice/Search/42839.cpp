#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_set>
#include <cmath>

using namespace std;

int isPrime(int N){
    if(N == 0 || N == 1) return 0;
    for(int i = 2; i <= sqrt(N); i++){
        if(N % i == 0) return 0;
    }
    return 1;
}

int solution(string numbers){
    unordered_set<int> uos;
    sort(numbers.begin(), numbers.end());
    do{
        for(int i = 1; i < numbers.size() + 1; i++){
            int x = stoi(numbers.substr(0, i));
            if(isPrime(x)) uos.insert(x);
        }
    }while(next_permutation(numbers.begin(), numbers.end())); 
    return uos.size();
}

int main(){
    cout << solution("17") << "\n";
    cout << solution("011") << "\n";
}