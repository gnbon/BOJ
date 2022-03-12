#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int num[10];
bool isused[10];

void solve(int lv)
{
    if (lv == m) {
        for (int i = 0; i < m; i++)
            cout << num[arr[i]] << " ";
        cout << "\n";
        return;
    }

    int st = 0;
    if (lv != 0) st = arr[lv-1];
    for (int i = st; i < n; i++) {
        if (isused[i]) continue;
        arr[lv] = i;
        isused[i] = 1;
        solve(lv+1);
        isused[i] = 0;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0 ; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num+n);
    solve(0);
}