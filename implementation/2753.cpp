#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int year;
	cin >> year;
	
	if (!(year % 4)) {
		if (year % 100 || !(year % 400)) {
			cout << 1;
			return 0;
		}
	}
	cout << 0;
}