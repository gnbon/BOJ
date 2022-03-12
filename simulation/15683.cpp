#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
int board1[10][10];
int board2[10][10];
vector<pair<int, int>> cctv;
int num_cctv, mn;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

bool OOB(int x, int y) {
    return (x < 0 || n <= x || y < 0 || m <= y);
}

void upd(int x, int y, int dir)
{
    dir %= 4;
    while(1) {
        x += dx[dir];
        y += dy[dir];
        if (OOB(x, y)) return;
        if (board1[x][y] == 6) return;
        if (board1[x][y] == 0)
            board2[x][y] = 7;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    mn = m*n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board1[i][j];
            if(board1[i][j] != 0 && board1[i][j] != 6) {
                cctv.push_back({i, j});
            }
        }
    }

    for(int tmp = 0; tmp < (1<<2*cctv.size()); tmp++) {
        for(int i = 0; i < n; i++)
            copy(board1[i], board1[i]+m, board2[i]);
        int brute=tmp;
        for(int i = 0; i < cctv.size(); i++) {
            int dir = brute % 4;
            brute /= 4;
            int x, y;
            tie(x, y) = cctv[i];
            if (board1[x][y] == 1) {
                upd(x, y, dir);
            }
            else if (board1[x][y] == 2) {
                upd(x, y, dir);
                upd(x, y, dir+2);
            }
            else if (board1[x][y] == 3) {
                upd(x, y, dir);
                upd(x, y, dir+1);
            }
            else if (board1[x][y] == 4) {
                upd(x, y, dir);
                upd(x, y, dir+1);
                upd(x, y, dir+2);
            }
            else {
                upd(x, y, dir);
                upd(x, y, dir+1);
                upd(x, y, dir+2);
                upd(x, y, dir+3);
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cnt += (board2[i][j] == 0);
        mn = min(mn, cnt);
    }
    cout << mn;
}