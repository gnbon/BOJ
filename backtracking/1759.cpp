#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i, n) for(int i = 0; i < (n); ++i)

string vowel = "aeiou";

int l, c;
string passSet;
string passWord;

void makePass(int len, int idx) {
    // base condition
    if (len == l) {
        int vowels = 0, consonants = 0;
        FOR(i, l) {
            if(vowel.find(passWord[i]) != -1) vowels++;
            else consonants++;
        }
        if(vowels >= 1 && consonants >= 2) cout << passWord << '\n';
        return;
    }

    for(int i = idx; i < c; i++) {
        passWord.push_back(passSet[i]);
        makePass(len + 1, i + 1); // idx + 1 for ascending order
        passWord.pop_back();
    }
}

int main()
{
    FASTIO;
    cin >> l >> c;
    FOR(i, c) {
        char tmp;
        cin >> tmp;
        passSet += tmp;
    }
    sort(passSet.begin(), passSet.end());
    makePass(0 ,0);
}