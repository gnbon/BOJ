#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> card(n + 1);
	
	vector<int> dp(n + 1, 0);
	
	for (int i = 1; i < n + 1; i++) {
		cin >> card[i];
	}
	
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < i + 1; j++) {
			dp[i] = max(dp[i - j] + card[j], dp[i]);
		}
	}
	
	cout << dp[n];
}