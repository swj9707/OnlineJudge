#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int numof;
	cin >> numof;
	int* div = new int[numof];
	for (int i = 0; i < numof; i++) {
		cin >> div[i];
	}
	sort(div, div + numof);
	cout << div[0] * div[numof - 1];
}