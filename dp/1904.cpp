#include <iostream>
using namespace std;

int memo[1000001];

int tile(int n) {
	if (n <= 2)
		return memo[n] = n;
	
	if (memo[n] != 0)
		return memo[n];
		
	else
		return memo[n] = (tile(n - 1) + tile(n - 2)) % 15746;
}

int main(void)
{
	int n;
	cin >> n;
	cout << tile(n);
}