#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000006;

int n, s0 = 0;
bool  a[maxn*2];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("lseq.inp", "r", stdin);
    freopen("lseq.out", "w", stdout);

    cin >> n;
    int t;

    int maxa = -maxn, mina = maxn;
    for (int i = 1; i <= n; i++) {
        cin >> t; t += maxn;
        if (t == maxn) s0++;
        else a[t] = true;
        maxa = max(maxa, t);
        mina = min(mina, t);
    }

    int l = mina, r = l-1;
    while (s0 > 0) if (!a[++r]) s0--;

    int mx = r - l + 1;
    while (r++ < maxa) { 
        if (!a[r]) while (a[l++]) {}
        mx = max(mx, r - l + 1);
    }

    cout << mx;


    return 0;
}