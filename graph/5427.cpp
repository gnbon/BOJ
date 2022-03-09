#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string board[1001];
int dist_1[1001][1001]; // 1: fire 2: sang
int dist_2[1001][1001];
queue<pair<int, int>> Q_1, Q_2;
int w, h;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs_1(void)
{
    while(!Q_1.empty()) {
        auto cur = Q_1.front(); Q_1.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (dist_1[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            dist_1[nx][ny] = dist_1[cur.X][cur.Y] + 1;
            Q_1.push({nx, ny});
        }
    }
}

void bfs_2(void)
{
    while(!Q_2.empty()) {
        auto cur = Q_2.front(); Q_2.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
                cout << dist_2[cur.X][cur.Y] + 1 << "\n";
                return;
            }
            if (dist_2[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            if (dist_1[nx][ny] >= 0 && dist_2[cur.X][cur.Y] + 1 >= dist_1[nx][ny]) continue;
            dist_2[nx][ny] = dist_2[cur.X][cur.Y] + 1;
            Q_2.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE" << "\n";
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> w >> h;
        for (int i = 0; i < h; i++) {
		    fill(dist_1[i], dist_1[i] + w, -1);
		    fill(dist_2[i], dist_2[i] + w, -1);
	    }
        for (int i = 0; i < h; i++) {
            cin >> board[i];
            for (int j = 0; j < w; j++) {
                if (board[i][j] == '*') {
                    dist_1[i][j] = 0;
                    Q_1.push({i, j});
                }
                if (board[i][j] == '@') {
                    dist_2[i][j] = 0;
                    Q_2.push({i, j});
                }
            }
        }
        bfs_1();
        bfs_2();
        Q_1 = queue<pair<int, int>>(); Q_2 = queue<pair<int, int>>();
    }
}