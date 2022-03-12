#include <bits/stdc++.h>
using namespace std;

int k;
int s[15];
int arr[15];

void solve(int lv, int st) {
    if (lv==6) {
        for (int i = 0; i < 6; i++)
            cout << s[arr[i]] << " ";
        cout << "\n";
    }

    for (int i=st; i<k; i++) {
        arr[lv] = i;
        solve(lv+1, i+1);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true) {
        cin >> k;
        if(!k) break;
        for (int i=0; i<k; i++)
            cin >> s[i];
        sort(s, s+k);
        solve(0, 0);
        cout << "\n";
    }
}