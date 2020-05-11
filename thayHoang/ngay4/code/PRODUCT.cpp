#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 123456789;
const int maxn = 100005;

// struct numMod { ll div, mod;
//     numMod(ll _div, ll _mod) {  div = _div; mod = _mod; }
// };
// numMod operator *(numMod a, numMod b) { return numMod(a.div + b.div + (a.mod*b.mod)/MOD, (a.mod*b.mod)%MOD); }
// numMod operator /(numMod a, numMod b) { return }
// bool operator <(numMod a, numMod b) { if (a.div != b.div) return a.div < b.div; else return a.mod < b.mod; }


int n, k;
ll a[maxn];

void Case() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    sort(a + 1, a + n + 1);
    // cout << n;

    ll res = 1;
    if (k % 2 == 0) {
        int l = 1, r = n;
        while (k > 0) {
            ll L = a[l] * a[l+1];
            ll R = a[r] * a[r-1];
            if (L >= R) { res = (res * L % MOD) % MOD; l+=2; }
            else { res = (res * R % MOD) % MOD; r-=2; }
            k-=2;
        }
    }
    else {
        if (a[n] < 0) while (k > 0) res = (res * a[n-(k--)+1]) % MOD;
        else {
            res = a[n]; k--;
            int l = 1, r = n-1;
            while (k > 0) {
                ll L = a[l] * a[l+1];
                ll R = a[r] * a[r-1];
                if (L > R) { res = (res * L % MOD) % MOD; l+=2; }
                else { res = (res * R % MOD) % MOD; r-=2; }
                k-=2;
            }
        }
    }
    cout << res << endl;
}

int main() 
{
    freopen("product.inp", "r", stdin);
    freopen("product.out", "w", stdout);

    int t;
    cin >> t;
    while (t--) Case();

    return 0;
}




/*

*** K chẵn
    sort tăng dần
    so sánh 2 thằng đầu và 2 thằng cuối

*** K lẻ
    sort tăng dần
    a[n] < 0    chọn k số lớn nhất
    else        chọn a[n] và ...


*/