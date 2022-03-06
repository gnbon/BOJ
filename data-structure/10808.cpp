#include <bits/stdc++.h>
using namespace std;

int alpha[26];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string S;
    cin >> S;

    for (auto c: S) 
        alpha[c-'a']++;

    for (auto e: alpha)
        cout << e << " ";
}