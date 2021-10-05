#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

float avg(int* Array, int N) {
	float sum;
	for (int i = 0; i < 5; i++) {
		sum += Array[i];
	}
	return sum / N;
}

int main() {
	int* Array = new int[5];
	for (int i = 0; i < 5; i++) {
		cin >> Array[i];
	}
	cout << avg(Array, 5) << '\n';
	sort(Array, Array + 5);
	cout << Array[2] << '\n';

}