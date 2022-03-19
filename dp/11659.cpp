#include <bits/stdc++.h>
using namespace std;

int n, m, i, j;
int seq[100001];
int dp[100001];

int main(void)
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> seq[i];
        dp[i] = dp[i-1] + seq[i];
    }
    while(m--) {
        cin >> i >> j;
        cout << dp[j] - dp[i-1] << "\n"; // prefix sum
    }
}