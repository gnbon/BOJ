#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int T[2190][2190]; // 3^7
int answer[3]; // count of -1, 0, 1

bool check(int x, int y, int len)
{
	int first = T[x][y];

	for (int i = x; i < x + len; i++) {
		for (int j = y; j < y + len; j++) {
			if (first != T[i][j])
				return false;
		}
	}
	return true;
}
void solve(int x, int y, int len)
{
	if (check(x, y, len)) {
		answer[T[x][y] + 1]++;
		return;
	}

	int div = len / 3;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			solve(x + div * i, y + div * j, div);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> T[i][j];
		}
	}

	solve(0, 0, N);

	for (int i = 0; i < 3; i++) {
		cout << answer[i] << "\n";
	}
}