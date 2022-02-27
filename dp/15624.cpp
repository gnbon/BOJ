#include <iostream>
using namespace std;

int memo[1000001];

int fibo(int n) {
	if (n <= 1)
		return memo[n] = n;
	
	if (memo[n] != 0)
		return memo[n];
		
	else
		return memo[n] = (fibo(n - 1) + fibo(n - 2)) % 1000000007;
}

int main(void)
{
	int n;
	cin >> n;
	cout << fibo(n);
}