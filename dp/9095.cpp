#include <iostream>
using namespace std;

int memo[11] = {1, 1, 2};

int solution(int n) {
	if (memo[n] != 0)
		return memo[n];
	else
		return memo[n] = (solution(n - 1) + solution(n - 2)) + solution(n - 3);
}

int main(void)
{
	int T, n;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << solution(n) << endl;
	}
}