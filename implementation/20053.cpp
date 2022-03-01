#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		int mn, mx;
		cin >> mn;
		mx = mn;
		for (int val, j = 1; j < N; j++) {
			cin >> val;
			mn = min(mn, val);
			mx = max(mx, val);

		}
		cout << mn << " " << mx << "\n";
	}
}