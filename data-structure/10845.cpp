#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    queue<int> Q;
    int n;
    cin >> n;
    while(n--) {
        string op;
        cin >> op;
        if (op == "push") {
            int x;
            cin >> x;
            Q.push(x);
        }
        else if (op == "pop") {
            if (Q.empty()) cout << "-1\n";
            else {
                cout << Q.front() << "\n";
                Q.pop();
            }
        }
        else if (op == "size")
            cout << Q.size() << "\n";
        else if (op == "empty")
            cout << Q.empty() << "\n";
        else if (op == "front") {
            if (Q.empty()) cout << "-1\n";
            else cout << Q.front() << "\n";
        }
        else { // if (op == "back")
            if (Q.empty()) cout << "-1\n";
            else cout << Q.back() << "\n";
        }
    }
}