#include <iostream>
using namespace std;

int memo[1001] = {0, 1, 2};

int solution(int n) {
	if (memo[n] != 0)
		return memo[n];
	else
		return memo[n] = (solution(n - 1) + solution(n - 2)) % 10007;
}

int main(void)
{
	int n;
	cin >> n;
	cout << solution(n) << endl;
}