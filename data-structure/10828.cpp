#include <bits/stdc++.h>
using namespace std;

stack <int> s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	
    string op;
    int val;
	for (int i = 0; i < N; i++) {
    	cin >> op;
        if (op == "push") {
            cin >> val;
            s.push(val);
        }
        else if (op == "pop") {
            if (s.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << s.top() << "\n";
            s.pop();
        }
        else if (op == "size") {
            cout << s.size() << "\n";
        }
        else if (op == "empty") {
            cout << s.empty() << "\n";
        }
        else if (op == "top") {
            if (s.empty()) {
                cout << -1 << "\n";
                continue;
            }
            cout << s.top() << "\n";
        }
    }
}