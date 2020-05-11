#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;
const int MOD = 998244353;

int64_t f[maxn];

void init_f() {
    f[0] = 1;
    for (int i = 1; i <= n; i++) f[i] = (f[i-1] * i) % MOD;
}

int64_t cnk(int k, int n) {
    return ((f[n]) / (f[k] * f[n-k])) % MOD;
}

int n, posx = 0, negx = 0, posy = 0, negy = 0;

int main()
{
    freopen("points.inp", "r", stdin);
    freopen("points.out", "w", stdout);

    cin >> n;
    int t;
    for (int i = 1; i <= n; i++) { 
        cin >> t;
        if (t > 0) posx++;
        else negx++;
    }
    for (int i = 1; i <= n; i++) { 
        cin >> t;
        if (t > 0) posy++;
        else negy++;
    }

    int64_t ans = 0;
    for (int points = 0; points <= n; points++) {
        int pos = posx - points;
        int diff = negy - pos;
        int neg = negx - diff;

        if (pos >= 0 && diff >= 0 && neg >= 0) {
            int64_t cntx = (cnk(posx, points) * cnk(negx, diff)) % MOD;
            int64_t cnty = (cnk(posy, points) * cnk(negy, diff)) % MOD;
            ans = (ans + (cntx * cnty) % MOD) % MOD;
        }
    }


    return 0;
}

/*

void Init() {
    f[0]=1; g[0]=1;
    f[1]=1; g[1]=1;
    for (int i=2;i<=n;i++) {
        f[i]=((f[i-1]%MOD)*(i%MOD))%MOD;
        g[i]=pw(f[i],MOD-2)%MOD;
    }
}
int C(int N, int K) { return (((f[N]*g[K])%MOD)*g[N-K])%MOD; }

*/