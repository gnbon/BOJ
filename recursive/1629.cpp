#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int pow_mod(ll a, ll b, ll c) {
    if (b == 1)
        return a % c;
    else if (b % 2) {
        ll val = pow_mod(a, (b - 1) / 2, c);
        return val * val % c;
    }
    else {
        ll val = pow_mod(a, b / 2, c);
        return val * a % c;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c;
    cin >> a >> b >> c;
    cout << pow_mod(a, b, c);
}