#include <bits/stdc++.h>
using namespace std;

vector<int> alpha(26, -1);
string S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> S;
	
	for (int i = 0; i < S.length(); ++i) {
		if (alpha[S[i] - 'a'] == -1) {
			alpha[S[i] - 'a'] = i;
		}
	}
	
	for (int i = 0; i < 26; ++i) {
		cout << alpha[i] << " ";
	}
}