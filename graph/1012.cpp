#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define MAX 50

int board[50][50];
bool vis[50][50];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int m, n, k;
queue<pair<int, int>> Q;

void bfs(int x, int y) {
    vis[x][y] = true;
    Q.push({x, y});
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (!board[nx][ny] || vis[nx][ny]) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    
    while(t--) {
        cin >> m >> n >> k;
        int x, y;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            board[y][x] = 1;
        }
        int cnt = 0; // cnt of earthworm
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] && !vis[i][j]) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
        for(int i = 0; i < n; i++) {
            fill(board[i], board[i] + m, 0);
            fill(vis[i], vis[i] + m, false);
        }
    }
}