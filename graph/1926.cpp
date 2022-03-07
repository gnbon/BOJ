#include <iostream>
#include <queue>
using namespace std;
#define X first
#define Y second
int graph[501][501];
bool visit[501][501];
int n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(int x, int y) {
	queue<pair<int, int>> Q;
	int cnt = 0;

	visit[x][y] = true;
	Q.push({x, y});
	while (!Q.empty()) {
		pair<int, int> cur = Q.front(); Q.pop();
		++cnt; // ++cnt when each node is popped
		for (int dir = 0; dir < 4; ++dir) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
			if (visit[nx][ny] || !graph[nx][ny]) continue;
			visit[nx][ny] = true;
			Q.push({nx, ny});
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m; // Store TC input
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			cin >> graph[x][y];
		}
	}

	int num_paint = 0, max_paint = 0; // BFS for every paintings
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < m; ++y) {
			if (graph[x][y] && !visit[x][y]) {
				++num_paint;
				int val = bfs(x, y);
				if (max_paint < val) max_paint = val;
			}
		}
	}

	cout << num_paint << "\n" << max_paint << "\n"; // Print output
}