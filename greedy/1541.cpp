#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    queue<int> Q;
    string op = "";
    int tmp = 0;

    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '-') {
            Q.push(tmp+stoi(op));
            tmp = 0; op = "";
        }
        else if (s[i] == '+') {
            tmp += stoi(op);
            op = "";
        }
        else
            op += s[i];
    }
    Q.push(tmp+stoi(op));

    int ans = Q.front(); Q.pop();
    while(!Q.empty()) {
        ans -= Q.front(); Q.pop();
    }

    cout << ans;
}