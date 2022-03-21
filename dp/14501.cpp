#include <bits/stdc++.h>
using namespace std;

int n, tmp;
int t[20];
int p[20];
int dp[20];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> t[i] >> p[i];

	for (int i = 0; i < n; i++) {
		dp[i] = max(dp[i], dp[i-1]);
		if (i + t[i] <= n)
			dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
	}

	cout << *max_element(dp, dp + n + 1);
}