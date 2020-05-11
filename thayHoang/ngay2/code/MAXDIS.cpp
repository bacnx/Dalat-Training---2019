#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int64_t maxn = 100005;

uint64_t Distance(int64_t a, int64_t b) { return (uint64_t)(a - b); }
int64_t Senter(int64_t a, int64_t b) { return b - (int64_t)(Distance(b, a)/2); }


int64_t n;
int64_t a[maxn], L, R;

int main() 
{
    freopen("maxdis.inp", "r", stdin);
    freopen("maxdis.out", "w", stdout);

    cin >> n >> L >> R;
    for (int64_t i = 1; i <= n; i++) cin >> a[i];

    sort(a + 1, a + n + 1);

    int64_t x;
    uint64_t mx = 0;

    if (R < a[1] && mx <= Distance(a[1], L)) { mx = Distance(a[1], L); x = L; }
    if (L > a[n] && mx <= Distance(R, a[n])) { mx = Distance(R, a[n]); x = R; }

    int64_t l = n + 1, r = 0;
    for (int64_t i = 1; i <= n; i++) if (L <= a[i]) {l = i; break; }
    for (int64_t i = n; i >= 1; i--) if (R >= a[i]) {r = i; break; }

    if (mx <= Distance(a[l], L)) { mx = Distance(a[l], L); x = L; }
    if (mx <= Distance(R, a[r])) { mx = Distance(R, a[r]); x = R; }

    for (int64_t i = l; i < r; i++) {
        int64_t k = Senter(a[i], a[i+1]);
        if (mx <= Distance(a[i+1], k)) {
            mx = Distance(a[i+1], k);
            x = k;
        }
    }

    cout << x;


    return 0;
}