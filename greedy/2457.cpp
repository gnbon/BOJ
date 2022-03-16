#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> flower;
    int sm, sd, em, ed;
    for (int i = 0; i < n; i++) {
        cin >> sm >> sd >> em >> ed;
        flower.push_back({sm * 100 + sd, em * 100 + ed});
    }

    sort(flower.begin(), flower.end());

    int t = 301;
    int ans = 0;
    while(t < 1201) {
        int nxt_t = t;
        for (int i = 0; i < n; i++) {
            if (flower[i].X <= t && flower[i].Y > nxt_t)
                nxt_t = flower[i].Y;
        }
        if (nxt_t == t) {
            cout << 0;
            return 0;
        }
        ans++;
        t = nxt_t;
    }

    cout << ans;
}