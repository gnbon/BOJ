#include <bits/stdc++.h>
using namespace std;
#define X 0
#define Y 1
#define Z 2
int board[101][101][101];
int dist[101][101][101];
int h, n, m;
int ans;
int dx[6] = {1, 0, -1, 0, 0 ,0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
queue<tuple<int, int, int>> Q;

void bfs(void) {
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		int curX, curY, curZ;
		tie(curX, curY, curZ) = cur;
		for (int dir = 0; dir < 6; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			int nz = curZ + dz[dir];
			if (nx < 0 || n <= nx || ny < 0 || m <= ny || nz < 0 || h <= nz) continue;
			if (dist[nx][ny][nz] >= 0) continue;
			dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
			Q.push({nx, ny, nz});
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> board[j][k][i];
				if (board[j][k][i] == 1)
					Q.push({j, k, i});
				if (board[j][k][i] == 0)
					dist[j][k][i] = -1;
			}
		}
	}

	bfs();	
	int ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (dist[j][k][i] == -1) {
					cout << -1;
					return 0;
				}
				ans = max(ans, dist[j][k][i]);
			}
		}
	}
	cout << ans;
}