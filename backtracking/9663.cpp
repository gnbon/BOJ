#include <bits/stdc++.h>
using namespace std;

int n;
int cnt;
int col[15];

bool check(int level) {
    for (int j = 0; j < level; j++) {
            if (col[j] == col[level]) return false;
            if (j+col[j] == level+col[level]) return false;
            if (j-col[j] == level-col[level]) return false;
    }
    return true;
}

void solve(int cur) {
    if (cur == n) {
        cnt++;
        return;
    }

    for (int j = 0; j < n; j++) {
        col[cur] = j;
        if (check(cur))
            solve(cur+1);
    }
}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    solve(0);

    cout << cnt;
}