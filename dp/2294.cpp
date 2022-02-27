#include <iostream>
#include <vector>
#include <algorithm>

#define INF 2e9
using namespace std;

int main(void)
{
	int n, k;
	int answer = 0;
	cin >> n >> k;
	
	vector<int> coin(n);
	vector<int> dp(k + 1, INF);
	
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
		dp[coin[i]] = 1;
	}
	
	for (int i = 1; i < k + 1; i++) {
		for (int j = 0; j < n; j++) {
			if (coin[j] < i)
				dp[i] = min(dp[i], dp[i - coin[j]] + 1);
		}
	}
	if (dp[k] == 2e9)
		cout << -1;
	else
		cout << dp[k];
}