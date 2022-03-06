#include <bits/stdc++.h>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	
	string ps;
	for (int i = 0; i < N; i++) {
		string answer = "YES";

		stack<char> s;
		cin >> ps;
		for (int j = 0; j < ps.length(); j++) {
			char cur = ps[j];
			if (cur == '(') {
				s.push('(');
			} else if (!s.empty() && cur == ')' && s.top() == '(') {
				s.pop();
			}
			else {
				answer = "NO";
				break;
			}
		}
		if (!s.empty()) answer = "NO";
		cout << answer << "\n";
	}
}