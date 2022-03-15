#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
pi s[100001];
int n, t, ans;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> s[i].second >> s[i].first;

    sort(s, s+n);

    for (int i = 0; i < n; i++) {
        if (t <= s[i].second) {
            t = s[i].first;
            ans++;
        }
    }

    cout << ans;
}