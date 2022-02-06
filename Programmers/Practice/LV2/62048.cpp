#include <iostream>
#include <cmath>
using namespace std;

long long gcd(int a, int b){
	long long c;
	while (b != 0){
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

long long solution(int w,int h) {
    long long answer = 1;
    long long gcdResult = gcd(w, h);
	long long W = w;
	long long H = h;
	long long all = W * H;
    answer = all - ((W / gcdResult) + (H / gcdResult) - 1) * gcdResult;
    return answer;
}