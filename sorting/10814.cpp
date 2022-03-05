#include <bits/stdc++.h>
using namespace std;

typedef struct {
    int age;
    string name;
    int join;
} member;

vector<member> v(100000);

bool compare(member a, member b) {
	if (a.age == b.age)
		return a.join < b.join;
	else 
		return a.age < b.age;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, i;
	cin >> N;
	
	for (i = 0; i < N; i++) {
        cin >> v[i].age;
		cin >> v[i].name;
        v[i].join = i;
	}


    sort(v.begin(), v.begin() + N, compare);

	for (i = 0; i < N; i++)
		cout << v[i].age << " " << v[i].name << "\n";
}