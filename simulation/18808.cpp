#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m, k;
int nb[40][40];
int r, c;
int st[10][10];

bool placeable(int x, int y) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!st[i][j]) continue;
            if (nb[x+i][y+j]) return false;
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!st[i][j]) continue;
            nb[x+i][y+j] = 1;
       }
    }
    return true;
}

void rotate() {
    int tmp[10][10];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            tmp[i][j] = st[i][j];
    for (int i = 0; i < c; i++)
        for (int j = 0; j < r; j++)
            st[i][j] = tmp[r - j - 1][i];
    swap(r, c);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    while(k--) {
        cin >> r >> c;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> st[i][j];

        for (int rt = 0; rt < 4; rt++) {
            bool flag = false;
            for (int x = 0; x <= n-r; x++) {
                if (flag == true) break;
                for (int y = 0; y <= m-c; y++) {
                    if (placeable(x, y)) {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag == true) break;
            rotate();
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cnt += nb[i][j];
        }
    }
    cout << cnt;
}