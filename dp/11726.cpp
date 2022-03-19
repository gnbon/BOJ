#include <iostream>
using namespace std;

int n;
int dp[1001] = {0, 1, 2};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	if(n <= 2) {
		cout << dp[n];
		return 0;
	}
	for(int i = 3; i <= n; i++)
		dp[i] = (dp[i-2] + dp[i-1]) % 10007;

	cout << dp[n];
}