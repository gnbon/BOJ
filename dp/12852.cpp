#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1000001];
int pre[1000001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    pre[1] = 0;
    for(int i = 2; i <= n; i++) {
        pre[i] = i-1;
        dp[i] = dp[i-1] + 1;
        if (!(i % 2) && dp[i/2] + 1 < dp[i]) {
            pre[i] = i/2;
            dp[i] = dp[i/2] + 1;
        }
        if (!(i % 3) && dp[i/3] + 1 < dp[i]) {
            pre[i] = i/3;
            dp[i] = dp[i/3] + 1;
        }
    }
    cout << dp[n] << "\n";
    while(n) {
        cout << n << " ";
        n = pre[n];
    }
}