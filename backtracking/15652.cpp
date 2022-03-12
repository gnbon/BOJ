#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void solve(int lv)
{
    if (lv == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = max(arr[lv-1], 1); i <= n; i++) {
        arr[lv] = i;
        solve(lv+1);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    arr[0] = 1;
    cin >> n >> m;
    solve(0);
}