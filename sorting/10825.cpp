#include <bits/stdc++.h>
using namespace std;

typedef struct {
    string name;
    int kor, eng, math;
} member;

vector<member> v(100000);

bool compare(member a, member b) {
	if (a.kor == b.kor) {
		if (a.eng == b.eng) {
			if (a.math == b.math) {
				return a.name < b.name;
			}
			return  b.math < a.math;
		}
		return a.eng < b.eng;
	}
	return b.kor < a.kor;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, i;
	cin >> N;
	
	for (i = 0; i < N; i++)
        cin >> v[i].name >> v[i].kor >> v[i].eng >> v[i].math;

    sort(v.begin(), v.begin() + N, compare);

	for (i = 0; i < N; i++)
		cout << v[i].name << "\n";
}