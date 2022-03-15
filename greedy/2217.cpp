#include <bits/stdc++.h>
using namespace std;

int arr[1000001];
int n, sz, ans, tmp;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    for (int i = n-1; i >= 0; i--) {
        tmp = arr[i]*++sz;
        ans = max(ans, tmp);
    }

    cout << ans;
}