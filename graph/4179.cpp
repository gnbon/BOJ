#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[1001];
int fire[1001][1001];
int dist[1001][1001];
int r, c;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		fill(fire[i], fire[i] + c, -1);
		fill(dist[i], dist[i] + c, -1);
	}
	queue<pair<int, int>> QJ, QF;
	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		board[i] = s;
		for (int j = 0; j < c; j++) {
			if (board[i][j] == 'J') {
				QJ.push({i, j});
				dist[i][j] = 0;
			}
			if (board[i][j] == 'F') {
				QF.push({i, j});
				fire[i][j] = 0;
			}
		}
	}

	while (!QF.empty()) {
		auto cur = QF.front(); QF.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || r <= nx || ny < 0 || c <= ny) continue;
			if (fire[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			fire[nx][ny] = fire[cur.X][cur.Y] + 1;
			QF.push({nx, ny});
		}
	}

	while (!QJ.empty()) {
		auto cur = QJ.front(); QJ.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || r <= nx || ny < 0 || c <= ny) {
				cout << dist[cur.X][cur.Y] + 1;
				return 0;
			}
			if (dist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			if (fire[nx][ny] != -1 && fire[nx][ny] <= dist[cur.X][cur.Y] + 1) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			QJ.push({nx, ny});
		}
	}
	cout << "IMPOSSIBLE";
}