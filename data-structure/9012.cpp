#include <bits/stdc++.h>
using namespace std;

stack <string> s;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin >> T;
	
    string a;
    int val;
	for (int i = 0; i < T; i++) {
        bool flag = true;
        cin >> a;
        for (int j = 0; j < a.length(); j++) {
            if (a.substr(j, 1) == "(") {
                s.push("(");
            }
            else if (a.substr(j, 1) == ")") {
                if (!s.empty() && s.top() == "(") {
                    s.pop();
                }
                else {
                    flag = false;
                    break;
                }
            }
        }
        if (s.empty() && flag) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}