#include <bits/stdc++.h>
using namespace std;

int tri[501][501];
int dp[501][501];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> tri[i][j];

    dp[1][1] = tri[1][1];

    for(int i = 2; i <= n; i++)
        for(int j = 1; j <= i; j++)
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + tri[i][j];

    cout << (int)*max_element(&dp[n][1], &dp[n][n+1]);
}