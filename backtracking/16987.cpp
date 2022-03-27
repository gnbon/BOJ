#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define S first
#define W second

typedef vector<pair<int, int>> vp;
int n;

int breakEgg(vp& egg, int idxEgg)
{
    // base condition
    if(idxEgg == n) {
        int broken = 0;
        FOR(i, n)
            if(egg[i].S <= 0) broken++;
        return broken;
    }

    int res = 0;
    bool beat = false; // flag for idxEgg that couldn't break egg

    FOR(i, n) {
        if(i == idxEgg) continue;
        if(egg[idxEgg].S <= 0 || egg[i].S <= 0) continue; // already broken egg
        beat = true;
        egg[idxEgg].S -= egg[i].W;
        egg[i].S -= egg[idxEgg].W;
        res = max(res, breakEgg(egg, idxEgg+1));
        egg[idxEgg].S += egg[i].W;
        egg[i].S += egg[idxEgg].W;
    }
    if (!beat)
        res = max(res, breakEgg(egg, idxEgg+1));
    return res;
}

int main()
{
    FASTIO;
    cin >> n;
    vp egg(n);
    FOR(i, n)
        cin >> egg[i].S >> egg[i].W;
    cout << breakEgg(egg, 0) << '\n';
}