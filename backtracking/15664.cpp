#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int num[10];
bool isused[10];

void solve(int lv, int st)
{
    if (lv == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    int tmp = 0;
    for (int i = st; i < n; i++) {
        if (tmp == num[i]) continue;
        arr[lv] = num[i];
        tmp = arr[lv];
        solve(lv+1, i + 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0 ; i < n; i++)
        cin >> num[i];
    sort(num, num+n);
    solve(0, 0);
}