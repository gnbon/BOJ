#include <bits/stdc++.h>
using namespace std;

int z(int n, int r, int c) {
    if (n == 0)
        return 0;
    int half = (1 << n-1);
    if (r < half && c < half)       return z(n-1, r, c);
    else if (r < half && c >= half) return z(n-1, r, c-half) + half*half;
    else if (r >= half && c < half) return z(n-1, r-half, c) + 2*half*half;
    else if (r >= half && c >= half)return z(n-1, r-half, c-half) + 3*half*half;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, r, c;
    cin >> n >> r >> c;
    cout << z(n, r, c);
}