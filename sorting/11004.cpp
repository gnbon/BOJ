#include <bits/stdc++.h>
using namespace std;

#define MAX 5000000

int a[MAX];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, K;
	cin >> N >> K;
	
	for (int i = 0; i < N; i++)
    	cin >> a[i];	

	nth_element(a, a + K - 1, a + N);
	cout << a[K - 1];
}