#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i, n) for(int i = 0; i < (n); ++i)
typedef pair<int, int> pi;

#define Y first
#define X second

#define LINE 5
string board[LINE];
bool selected[LINE][LINE];

int dy[4] = {0, 0, 1,-1};
int dx[4] = {1,-1, 0, 0};

bool isLinked(int y, int x) { // bfs
    bool visited[LINE][LINE];
    FOR(i, LINE)
        fill(visited[i], visited[i] + LINE , 0);
    queue<pi> Q;
    visited[y][x] = 1; // last (x, y) is in selected[][]
    int cnt = 1;
    Q.push({y, x});

    while(!Q.empty()) {
        pi cur = Q.front(); Q.pop();
        FOR(dir, 4) {
            int ny = cur.Y + dy[dir];
            int nx = cur.X + dx[dir];
            if(ny < 0 || ny >= LINE || nx < 0 || nx >= LINE) continue;
            if(visited[ny][nx]) continue;
            if(!selected[ny][nx]) continue;
            visited[ny][nx] = 1;
            cnt++;
            Q.push({ny, nx});
        }
    }
    if(cnt == 7) return true;
    else return false;
}

int selectPrincess(int y, int x, int studentCnt, int somCnt) // dfs
{
    // base condition
    if(studentCnt-somCnt >= 4) // yeonCnt is always under 4
        return 0;

    if(studentCnt == 7) {
        if(somCnt >= 4 && isLinked(y, x)) return 1;
        else return 0;
    }

    int res = 0;
    for(int i = y; i < LINE; i++) {
        for(int j = (i == y ? x : 0); j < LINE; j++) {
            if(selected[i][j]) continue;
            selected[i][j] = 1;
            res += selectPrincess(i, j, studentCnt+1, somCnt + (board[i][j] == 'S'));
            selected[i][j] = 0;
        }
    }
    return res;
}

int main()
{
    FASTIO;
    FOR(y, LINE)
        cin >> board[y];

    cout << selectPrincess(0, 0, 0, 0) << '\n';
}