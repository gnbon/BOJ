#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    queue<int> Q;
    cin >> n;
    for(int i = 1; i <= n; i++) Q.push(i);
    while(Q.size() >= 2) {
        Q.pop();
        int val = Q.front(); Q.pop();
        Q.push(val);
    }
    cout << Q.front();
}