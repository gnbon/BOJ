#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, idx, loc;
	int cnt = 0;
	cin >> N;
	vector<int> vec(N + 1,-1);

	for (int i = 0; i < N; i++) {
		cin >> idx;
		cin >> loc;
		if (vec[idx] != -1 && vec[idx] != loc)
			cnt++;
		vec[idx] = loc;
	}
	
	cout << cnt;
}