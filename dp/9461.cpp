#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n;
ll dp[101] = {0, 1, 1, 1, 2, 2};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for (int i = 6; i <= 100; i++)
		dp[i] = dp[i-1] + dp[i-5];

	while(t--) {
		cin >> n;
		cout << dp[n] << "\n";
	}
}