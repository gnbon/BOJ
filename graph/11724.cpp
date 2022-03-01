#include <bits/stdc++.h>
using namespace std;

#define MAX 25

typedef vector<int> vi;

int n;
int graph[MAX][MAX];
bool visited[MAX][MAX];
int house_cnt;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

vi vec;

void dfs(int x, int y) {
	house_cnt++;
	visited[x][y] = true;
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0|| n <= nx || ny < 0|| n <= ny)
			continue;
		if (graph[nx][ny] && !visited[nx][ny])
			dfs(nx, ny);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

 	for (int i = 0; i < n; i++) {
    	string s; 
		cin >> s;
		for (int j = 0; j < n; j++) {
			graph[i][j] = s.at(j) - '0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			house_cnt = 0;
			if (graph[i][j] && !visited[i][j]) {
				dfs(i, j);
				vec.push_back(house_cnt);
			}
		}
	}
	
	sort(vec.begin(), vec.end());
	
	cout << vec.size() << "\n";
	
	for (int i = 0; i < vec.size(); i++) {
    	cout << vec[i] << "\n";
    } 
}