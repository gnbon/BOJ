#include <bits/stdc++.h>
using namespace std;

int main(void)
{	
	string S;
	while (getline(cin, S)) {
		int lower = 0, upper = 0, number = 0, space = 0;
		for (int i = 0; i < S.length(); ++i) {
			if ('a' <= S[i] && S[i] <= 'z')
				++lower;
			else if ('A' <= S[i] && S[i] <= 'Z')
				++upper;
			else if ('0' <= S[i] && S[i] <= '9')
				++number;
			else if (S[i] == ' ')
				++space;
		}
		printf("%d %d %d %d\n", lower, upper, number, space);
	}
}