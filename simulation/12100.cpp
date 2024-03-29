#include <bits/stdc++.h>
using namespace std;

int n;
int board1[20][20];
int board2[20][20];

void rotate() {
    int tmp[20][20];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tmp[i][j] = board2[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board2[i][j] = tmp[n-1-j][i];
}

void tilt(int dir) {
    while (dir--) rotate();
    for (int i = 0; i < n; i++) {
        int tilted[20] = {};
        int idx = 0;
        for (int j = 0; j < n; j++) {
            if (!board2[i][j]) continue;
            if (!tilted[idx])
                tilted[idx] = board2[i][j];
            else if(tilted[idx] == board2[i][j])
                tilted[idx++] *= 2;
            else
                tilted[++idx] = board2[i][j];
        }
        for (int j = 0; j < n; j++) board2[i][j] = tilted[j];
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board1[i][j];

    int mx = 0;
    for (int tmp = 0; tmp < (1<<2*5); tmp++) {
        for(int i = 0; i < n; i++)
            copy(board1[i], board1[i]+n, board2[i]);
        int brute = tmp;
        for (int i = 0; i < 5; i++) {
            int dir = brute % 4; brute /= 4;
            tilt(dir);
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mx = max(mx, board2[i][j]);
    }

    cout << mx;
}