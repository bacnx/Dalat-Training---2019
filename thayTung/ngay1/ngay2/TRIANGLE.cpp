#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("triangle.inp", "r", stdin);
    freopen("triangle.out", "w", stdout);

    int a, b, c;
    cin >> a >> b >> c;

    int res = 0;
    if (a < b) swap(a, b);
    if (a < c) swap(a, c);
    if (a > b + c) res = a - (b + c) + 1;

    cout << res;

    return 0;
}