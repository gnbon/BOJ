#include <bits/stdc++.h>
using namespace std;

int stock[14];

int bnp(int money) {
	int reserve = 0;
	for (int i = 0; i < 14; i++) {
		while (stock[i] <= money) {
			money -= stock[i];
			reserve++;
		}
	}
	return money + reserve * stock[13];
}

int timing(int money) {
	int reserve = 0;
	int flag_up = 0;
	int flag_down = 0;

	for (int i = 1; i < 14; i++) {
		if (stock[i] < stock[i - 1])
			flag_down++;
		else
			flag_down = 0;
		
		if (stock[i - 1] < stock[i])
			flag_up++;
		else
			flag_up = 0;
		
		if (flag_down == 3) {
			flag_down = 0;
			while (stock[i] <= money) {
				money -= stock[i];
				reserve++;
			}
		}
		
		if (flag_up == 3) {
			flag_up = 0;
			if (reserve) {
				money += stock[i] * reserve;
				reserve = 0;
			}
		}
	}
	return money + reserve * stock[13];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int money;
	
	cin >> money;
	for (int i = 0; i < 14; i++) {
		cin >> stock[i];
	}
	
	int junhyun = bnp(money);
	int sungmin = timing(money);
	
	if (sungmin < junhyun)
		cout << "BNP";
	else if (junhyun < sungmin)
		cout << "TIMING";
	else
		cout << "SAMESAME";
	return 0;
}