#include <iostream>
#include <algorithm>
#define MAX 50
using namespace std;

char data[MAX][MAX];
int Answer, N;

void check() {
	char c;
	for (int i = 0; i < N; i++) { 
		int count = 1; 
		c = data[i][0];
		for (int j = 1; j < N; j++) {
			if ((data[i][j] == c)) {
				count += 1;
			}
			else count = 1;
			c = data[i][j];
			if (count > Answer) Answer = count;
		}
	}

	for (int j = 0; j < N; j++) { // ¿­ °è»ê
		int count = 1;
		c = data[0][j];
		for (int i = 1; i < N; i++) {
			if ((data[i][j] == c)) {
				count += 1;
			}
			else count = 1;
			c = data[i][j];
			if (count > Answer) Answer = count;
		}
	}
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> data[i][j];
	}	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N-1; j++) {
			swap(data[i][j], data[i][j + 1]);
			check();
			swap(data[i][j], data[i][j + 1]);
		}
	}	
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N-1; i++) {
			swap(data[i][j], data[i+1][j]);
			check();
			swap(data[i][j], data[i+1][j]);
		}
	}
	cout << Answer << '\n';
}