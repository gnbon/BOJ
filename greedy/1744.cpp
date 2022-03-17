#include <bits/stdc++.h>
using namespace std;


int n, t, tmp, ans;
int arr[51];
vector<int> seqP;
vector<int> seqN;

void seqSum(vector<int> v) {
    while (1 < v.size()) {
        ans += *(v.end() - 1) * *(v.end() - 2);
        v.pop_back(); v.pop_back();
    }
    if (v.size())
        ans += v[0];
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t == 1) ans++;
        else if (t > 0)
            seqP.push_back(t);
        else
            seqN.push_back(t);
    }

    sort(seqP.begin(), seqP.end());
    sort(seqN.begin(), seqN.end(), greater<>());
    seqSum(seqP);
    seqSum(seqN);
    cout << ans;
}