#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second
int graph[101][101];
int n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int x, int y) {
	queue<pair<int, int>> Q;
	graph[x][y] = 1;

	Q.push({x, y});
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
			if (graph[nx][ny] == -1 || graph[nx][ny]) continue;
			graph[nx][ny] = graph[cur.X][cur.Y] + 1;
			Q.push({nx, ny});
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			graph[i][j] = s[j] - '0' - 1;
		}
	}
	bfs(0, 0);
	cout << graph[n - 1][m - 1];
}