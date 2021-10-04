#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool compareLength(string A, string B) {
	if (A.length() == B.length()) return A < B;
	return A.length() < B.length();
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<string> vecstr;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		if(find(vecstr.begin(), vecstr.end(), str) == vecstr.end()) vecstr.push_back(str);
	}
	sort(vecstr.begin(), vecstr.end(), compareLength);
	for (int i = 0; i < vecstr.size(); i++) {
		cout << vecstr[i] << '\n';
	}
}