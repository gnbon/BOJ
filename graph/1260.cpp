#include <iostream>
#include <queue>
using namespace std;

int graph[1001][1001];
bool visit[1001];
int N, M, V;

void init() { 
  for (int i = 0; i <= 1000; i++) 
	  visit[i] = false;
}

void dfs(int s) {
	int i;
	cout << s << " ";
	visit[s] = true;

 	for(i = 1; i <= N; i++) 
		if (graph[s][i] && !visit[i]) 
			dfs(i);
	
	if (i == N) 
		return;
}

void bfs(int pos) {
  queue <int> q;
  int i = 0;
  
  q.push(pos);
  visit[pos] = true;
  
  while(!q.empty()) {
    int newPos = q.front();
    visit[newPos] = true;
  	cout << newPos<< " ";
    q.pop();
    
    for (i = 1; i <= N; i++) {
      if(graph[newPos][i] && !visit[i]) {
        visit[i] = true;
        q.push(i);
      }
    }
  }
}

int main() {
	int i, j, src, dest;

 	cin >> N >> M >> V;

 	for (i = 1; i <= M; i++) {
    	cin >> src >> dest;
    	graph[src][dest] = 1;
    	graph[dest][src] = 1;
	}

 	dfs(V);
	cout << endl;
 	
	init();
 	bfs(V);
	cout << endl;


  return 0;
}