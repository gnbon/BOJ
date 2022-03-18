#include <iostream>
using namespace std;

int t, n;
int dp[11] = {0, 1, 2, 4};

int main(void)
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 4; i <= n; i++)
			dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
		cout << dp[n] << "\n";
	}
}