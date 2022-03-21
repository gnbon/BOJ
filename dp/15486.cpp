#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int t[1500001];
int p[1500001];
ll dp[1500001];

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