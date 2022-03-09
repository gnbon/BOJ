#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dist[301][301];
queue<pair<int, int>> Q;
int l;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

void bfs(pair<int, int> start) {
	dist[start.X][start.Y] = 0;
	Q.push({start.X, start.Y});

	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 8; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
			if (dist[nx][ny] >= 0) continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({nx, ny});
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> l;
		for (int i = 0; i < l; i++)
			fill(dist[i], dist[i] + l, -1);	
		pair<int, int> start;
		pair<int, int> end;
		cin >> start.X >> start.Y;
		cin >> end.X >> end.Y;
		bfs(start);
		cout << dist[end.X][end.Y] << "\n";

	}
}