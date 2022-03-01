#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi graph[1001];
bool visited[1001];

int cnt = 0;

void dfs(int v) {
	visited[v] = true;
	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];
		if (!visited[next]) {
			dfs(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	int src, dest;

 	cin >> n;
	cin >> m;

 	for (int i = 1; i <= m; i++) {
    	cin >> src >> dest;
    	graph[src].push_back(dest);
		graph[dest].push_back(src);
	}
	
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			cnt++;
		}
	}
	
	cout << cnt;
}