#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	for(int i = 0 ; i < n; i++){
		int p, ans = 0, max = -9999;
		cin >> p;
		vector <pair<int, string>> s(p);
		for(int j = 0 ; j < p; j++){
			cin >> s[j].first >> s[j].second;
			if(s[j].first > max) {
				max = s[j].first;
				ans = j;
			}
		}
		cout << s[ans].second << endl;
	}
}