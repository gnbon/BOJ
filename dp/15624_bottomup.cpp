#include <iostream>
using namespace std;

int memo[1000001] = {0, 1};

int main(void)
{
	int n;

	cin >> n;
	
	for (int i = 2; i <= n; i++)
		memo[i] = (memo[i - 1] + memo[i - 2]) % 1000000007;

	cout << memo[n];
}