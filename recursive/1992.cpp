#include <bits/stdc++.h>
using namespace std;

int n;
string arr[64];

bool check(int n, int x, int y) {
    if (n == 1) return true;
    char st = arr[x][y];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (arr[x+i][y+j] != st)
                return false;
    return true;
}

string solve(int n, int x, int y) {
    string ans;
    if (check(n, x, y)) {
        ans = arr[x][y];
        return ans;
    }

    ans = "(";
    int half = n / 2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ans += solve(half, x+i*half, y+j*half); // split into 4 pieces
        }
    }
    return ans + ")";
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << solve(n, 0, 0);
}