#include <bits/stdc++.h>
using namespace std;

int freq[10];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B, C, mul;

    cin >> A >> B >> C;
    mul = A*B*C;
    
    while (mul) {
        freq[mul%10]++;
        mul /= 10;
    }

    for (auto e: freq)
        cout << e << "\n";
}