#include <bits/stdc++.h>
using namespace std;

int freq[10];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    while (N) {
        freq[N % 10]++;
        N /= 10;
    }

    freq[6] = (freq[6] + freq[9] + 1) / 2;
    cout << *max_element(freq, freq + 9);
}