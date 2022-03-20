#include <iostream>
using namespace std;

int n;
int mod = 10007;
int dp[1001] = {0, 1, 3};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	if(n <= 2) {
		cout << dp[n];
		return 0;
	}
	for(int i = 3; i <= n; i++)
		dp[i] = (dp[i-2]*2 + dp[i-1]) % mod;
	cout << dp[n];
}