#include <iostream>
#include <queue>

using namespace std;

#define MAX 1000

int graph[MAX][MAX];
queue<pair<int, int>> q;

int M, N;
int days;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(void) {
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || N <= nx || ny < 0 || M <= ny)
				continue;
			if (graph[nx][ny] == 0) {
				graph[nx][ny] = graph[cur.first][cur.second] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int fruit;

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> fruit;
			graph[i][j] = fruit;

			if (graph[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}

	bfs();
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 0) {
				cout << -1;
				return 0;
			}
			if (days < graph[i][j])
				days = graph[i][j];
		}
	}

	cout << days - 1;
}