#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int n, m;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<pair<int, int>> chicken_tmp;

int dist_city() {
    int dist_city = 0;
    for (auto h: house) {
        int dist_house = INT_MAX;
        for (auto c: chicken_tmp) {
            int tmp = abs(h.X-c.X) + abs(h.Y-c.Y);
            dist_house = min(dist_house, tmp);
        }
        dist_city += dist_house;
    }
    return dist_city;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int val;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> val;
            if (val == 1) house.push_back({i, j});
            if (val == 2) chicken.push_back({i, j});
        }
    }

    int mn = INT_MAX;
    for (int tmp = 0; tmp < (1<<chicken.size()); tmp++) {
        if (__builtin_popcount(tmp) != m) continue;
        int brute = tmp;
        for (int i = 0; i < chicken.size(); i++) {
            bool flag = brute % 2;
            brute /= 2;
            if (flag) chicken_tmp.push_back(chicken[i]);
        }
        mn = min(mn, dist_city());
        chicken_tmp.clear();
    }
    cout << mn;
}