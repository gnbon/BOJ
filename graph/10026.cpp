#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
string board[101];
bool vis[101][101];
int n;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int x, int y) {
    queue<pair<int, int>> Q;
    char color = board[x][y];
    vis[x][y] = true;
    Q.push({x, y});
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (board[nx][ny] != color || vis[nx][ny]) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

int area(void) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!vis[i][j]) {
                cnt++;
                bfs(i, j);
            }
        }
    }
    return cnt;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    for (int i = 0; i < n; i++) cin >> board[i];
    int not_g = area();

    for(int i = 0; i < n; i++)
        fill(vis[i], vis[i] + n, false);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (board[i][j] == 'R') board[i][j] = 'G'; // change R->G for color blindness

    int is_g = area();

    cout << not_g << " " << is_g;
}