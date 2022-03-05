#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

vector<pair<int, int>> v(100001);

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	else 
		return a.second < b.second;
		
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, i;
	cin >> N;
	
	for (i = 0; i < N; i++) {
        cin >> v[i].first;
		cin >> v[i].second;
	}


    sort(v.begin(), v.begin() + N, compare);

	for (i = 0; i < N; i++)
		cout << v[i].first << " " << v[i].second << "\n";
}