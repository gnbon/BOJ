#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num;
	bool submit[31] = {false};

	for (int i = 0; i < 28; i++) {
		cin >> num;
		submit[num] = true;
	}

	for (int i = 1; i <= 30; i++) {
		if (!submit[i])
			cout << i << "\n";
	}
}