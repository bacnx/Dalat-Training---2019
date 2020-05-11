#include <bits/stdc++.h>
using namespace std;

const int maxn = 1003;

int m, n, a[maxn][maxn];

void sub1() {
    if (a[1][1] == a[2][2]) cout << "4";
    else cout << "1";
}

void sub2() {
    vector<int> t;
    for (int i = 1; i <= n; i++) 
        
}

int main() 
{
    freopen("pikachu.inp", "r", stdin);
    freopen("pikachu.out", "w", stdout);

    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) 
            cin >> a[i][j];
    if (m == 2) sub2();
    // if (n == 2 && m == 2) sub1();
    // else if (m == 2) sub2();
    // else cout << "-1";

    return 0;
}