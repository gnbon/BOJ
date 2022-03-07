#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    list<char> editor;
    editor.push_back('!');
    for (auto e: s) editor.push_back(e);
    auto cursor = --editor.end();

    int m;
    cin >> m;

    char op;
    for (int i = 0; i < m; i++) {
        cin >> op;
        switch(op) {
            case 'L':
                if (cursor != editor.begin())
                    cursor--;
                break;
            case 'D':
                if (cursor != --editor.end())
                    cursor++;
                break;
            case 'B':
                if (cursor != editor.begin())
                    editor.erase(cursor--);
                break;
            case 'P':
                char $;
                cin >> $;
                editor.insert(++cursor, $);
                --cursor;
                break;
            default:
                break;
        }
    }

    for (auto iter = ++editor.begin(); iter != editor.end(); iter++) 
        cout << *iter;
}