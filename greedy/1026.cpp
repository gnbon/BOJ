#include <bits/stdc++.h>
using namespace std;

int a[50];
int b[50];
int n, sum;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    sort(a, a+n);
    sort(b, b+n, greater<int>());

    for (int i = 0; i < n; i++) {
        sum += a[i] * b[i];
    }

    cout << sum;
}