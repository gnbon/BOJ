#include <bits/stdc++.h>
using namespace std;

vector <int> v(10000, 0);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, val;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
    	cin >> val;
		++v[val];
	}

	for (int i = 0; i <= 10000; i++) {
		if (v[i]) {
			for (int j = 0; j < v[i]; j++) {
				cout << i << "\n";
			}
		}
	}
}