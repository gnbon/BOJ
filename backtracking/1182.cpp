#include <bits/stdc++.h>
using namespace std;

int n, s, cnt;
int seq[20];

void solve(int cur, int tot) {
    if (cur == n) {
        if (tot == s) cnt++;
        return;
    }
    solve(cur+1, tot);
    solve(cur+1, tot+seq[cur]);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> seq[i];
    solve(0, 0);
    if (s == 0) cnt--;
    cout << cnt;
}