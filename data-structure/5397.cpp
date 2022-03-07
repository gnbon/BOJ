#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    while(N--) {
        string TC;
        cin >> TC;

        list<char> a;
        auto c = a.begin();
        for (auto e: TC) {
            switch(e) {
                case '<':
                    if (c != a.begin()) c--;
                    break;
                case '>':
                    if (c != a.end()) c++;
                    break;
                case '-':
                    if (c != a.begin()) {
                        c--;
                        c = a.erase(c);
                    }
                    break;
                default:
                    c = a.insert(c, e);
                    if (c != a.end())
                        c++;
                    break;
            }
        }
    for (auto e: a) cout << e;
    cout << "\n";
    }
}