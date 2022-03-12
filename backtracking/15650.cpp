#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
int isused[10];

void solve(int k) {
    if (k == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";
        return;
    }

    int st = 1;
    if (k != 0) st = arr[k-1] + 1;
    for (int i = st; i <= n; i++) {
        if (!isused[i]) {
            arr[k] = i;
            isused[i] = true;
            solve(k+1);
            isused[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    solve(0);
}