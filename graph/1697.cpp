#include <iostream>
#include <queue>

using namespace std;

#define MAX 100000

queue<int> q;
int visit[100001];

int N, K;

bool valid(int node) {
	if (node < 0 || MAX < node || visit[node])
		return false;

	return true;
}

int bfs(int start) {
	q.push(start);
	visit[start] = 1;
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == K)
			return visit[cur] - 1;

		if (valid(cur - 1)) {
			q.push(cur - 1);
			visit[cur - 1] = visit[cur] + 1;
		}
		if (valid(cur + 1)) {
			q.push(cur + 1);	
			visit[cur + 1] = visit[cur] + 1;
		}
		if (valid(cur * 2)) {
			q.push(cur * 2);
			visit[cur * 2] = visit[cur] + 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	cout << bfs(N);
}