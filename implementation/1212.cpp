#include <bits/stdc++.h>
using namespace std;

string binary[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};
string binary_first[8] = {"0", "1", "10", "11", "100", "101", "110", "111"};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string input;

	cin >> input;
	
	if (!(input[0] - '0')) {
		cout << 0;
		return 0;
	}

	cout << binary_first[input[0] - '0'];
	
	for (int i = 1; i < input.size(); i++)
		cout << binary[input[i] - '0'];
}