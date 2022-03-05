#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

typedef long long ll;

ll a[MAX];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
    	cin >> a[i];	

	sort(a, a + N);

	ll result = a[0], count = 1;
	int max = 1;

	for (int i = 0; i < N; ++i) {
		if (a[i] == a[i - 1]) {
			++count;
		}
		else {
			if (max < count) {
				max = count;
				result = a[i - 1];
			}
		count = 1;
		}
	}

	if (max < count) {
		max = count;
		result = a[N - 1];
	}

	cout << result;
}