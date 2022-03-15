#include <bits/stdc++.h>
using namespace std;

int arr[1001];
int n, sum, tmp;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr+n);

    for (int i = 0; i < n; i++) {
        tmp += arr[i];
        sum += tmp;
    }

    cout << sum;
}