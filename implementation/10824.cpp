#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{	
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a, b, c, d;
	cin >> a >> b >> c >> d;
	
	ll ab = stoll(a + b);
	ll cd = stoll(c + d);
	
	cout << ab + cd;
}