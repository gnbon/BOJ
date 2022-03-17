#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n;
int stock_value[1000001];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> stock_value[i];
        int max_stock = 0;
        ll profit_sum = 0;
        for (int day = n - 1; day >= 0; day--) {
            if (max_stock < stock_value[day])
                max_stock = stock_value[day];
            profit_sum += max_stock - stock_value[day];
        }
        cout << profit_sum << "\n";
    }
}