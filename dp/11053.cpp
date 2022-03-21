#include <bits/stdc++.h>
using namespace std;

int n;
int seq[1001];
int dp[1001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++)
    	cin >> seq[i];
	fill(dp, dp + n, 1);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			if (seq[j] < seq[i])
				dp[i] = max(dp[i], dp[j] + 1);

	cout << *max_element(dp, dp + n);
}