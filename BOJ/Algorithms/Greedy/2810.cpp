#include<iostream>
#include<algorithm>
using namespace std;

int n;
char c;
bool flag;
double sum;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> c;
		if (c == 'S') sum++;
		else //(c == 'L')
		{
			flag = true;
			sum += 0.5;
		}	
	}
	
	if (flag) cout << sum + 1;
	else cout << sum;

	
}