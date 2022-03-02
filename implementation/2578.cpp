#include <bits/stdc++.h>
using namespace std;

#define LINE 5

int board[LINE][LINE];
int cnt;

void input(void) {
	for (int i = 0; i < LINE; i++) {
		for (int j = 0; j < LINE; j++) {
			cin >> board[i][j];
		}
	}
}

bool check() {
	int bingo = 0;
	
	for (int i = 0; i < LINE; i++) {
		for (int j = 0; j < LINE; j++) {
			if (board[i][j])
				break;
			if (j == LINE - 1)
				bingo++;
		}
	}
	
	for (int i = 0; i < LINE; i++) {
		for (int j = 0; j < LINE; j++) {
			if (board[j][i])
				break;
			if (j == LINE - 1)
				bingo++;
		}
	}
	
	for (int i = 0; i < LINE; i++) {
		if (board[i][i])
			break;
		if (i == LINE - 1)
			bingo++;
	}

	for (int i = 0; i < LINE; i++) {
		if (board[i][LINE -1 - i])
			break;
		if (i == LINE - 1)
			bingo++;
	}
	
	if (bingo >= 3)
		return true;
	return false;
}

void game(void) {
	int val;
	while (true) {
		cin >> val;
		cnt++;
		for (int i = 0; i < LINE; i++) {
			for (int j = 0; j < LINE; j++) {
				if (board[i][j] == val) {
					board[i][j] = 0;
					if (check()) 
						return;
				}
				
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	input();
	game();
	cout << cnt;
}