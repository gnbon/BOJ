#include <iostream>
using namespace std;

char board[10][10];
char answer[10][10];
int n;

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void read_board() {
	cin >> n;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			cin >> board[x][y];
		}
	}
}

void read_game() {
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			cin >> answer[x][y];
		}
	}
}

void print_mine() {
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			cout << answer[x][y];
		}
		cout << '\n';
	}
}

int num_mine(int x, int y) {
	int nx, ny;
	int num = 0;
	for (int i = 0; i < 8; i++) {
		nx = x + dx[i]; ny = y + dy[i];
		if ((nx < 0 || n <= nx) || (ny < 0 || n <= ny))
			continue;
		if (board[nx][ny] == '*') 
			num++;
	}
	
	return num;
}

void write_mine() {
	bool flag = false;

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (answer[x][y] == 'x') {
				if (board[x][y] == '*') {
					flag = true;
				}
				answer[x][y] = num_mine(x, y) + '0';
			}
		}
	}
	
	if (flag) {
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				if (board[x][y] == '*') {
					answer[x][y] = '*';
				}
			}
		}
	}

	print_mine();
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	read_board();
	read_game();
	write_mine();
}