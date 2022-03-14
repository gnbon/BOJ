#include <bits/stdc++.h>
using namespace std;

int n;
string star[6561];

void space(int n, int x) {
    if (n == 1) {
        star[x] += " ";
        return;
    }

    n /= 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            space(n, x+i*n);
}

void solve(int n, int x) {
    if (n == 1) {
        star[x] += "*";
        return;
    }

    n /= 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) space(n, x+i*n);
            else solve(n, x+i*n);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    solve(n, 0);
    for (int i = 0; i < n; i++) {
        cout << star[i];
        cout << "\n";
    }
}