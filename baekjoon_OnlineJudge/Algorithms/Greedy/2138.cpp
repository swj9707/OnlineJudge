#include <iostream>
#include <string>


using namespace std;

void chgLight(char value) {
	if (value == '0') return '1';
	else return '0';
}

void chgSwitch(string Lights, int N) {
	if (N == 0) {
		Lights[N] = chgLight(Lights[N]);
		Lights[N+1] = chgLight(Lights[N+1]);
	}
	else if(N == )
}

int main() {

}