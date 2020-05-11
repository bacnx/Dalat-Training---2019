#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("coca.inp", "r", stdin);
    freopen("coca.out", "w", stdout);

    int c = 0;
    char t, s;
    cin >> t;
    while (true) {
        s = ' ';
        cin >> s;
        if (s == ' ') break;
        if (s != t) c++;
        t = s;
    }

    if ( c % 2 != 0 ) cout << "Win";
    else cout << "Lose";

    return 0;
}