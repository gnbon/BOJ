#include <bits/stdc++.h>
using namespace std;

int n;
int seq[100001];
int dp[100001];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
        cin >> seq[i];
        dp[i] = seq[i];
    }
	for(int i = 1; i <= n; i++)
		dp[i] = max(dp[i], dp[i-1] + seq[i]);
	cout << *max_element(dp+1, dp+n+1);
}