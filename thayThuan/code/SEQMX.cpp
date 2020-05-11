#include <bits/stdc++.h>
using namespace std;

const int maxn = 100050;
const double eps = 0.00000001;

int n, k;
int a[maxn];
double b[maxn], ma[maxn];

bool check(double tb) {
    b[0] = 0;
    for (int i = 1; i <= n; i++){
        b[i] = (double)a[i] - tb;
        if (ma[i-1] <= 0) ma[i] = b[i];
        else ma[i] = ma[i-1] + b[i];
    }
    for (int i = 1; i <= n; i++) 
        b[i] += b[i-1];

    for (int i = k; i <= n; i++) {
        if (0.0 <= (b[i]-b[i-k] + max(0.0, ma[i-k]))) return true;
    }    

    return false;
}

int main()
{
    freopen("seqmx.inp", "r", stdin);
    freopen("seqmx.out", "w", stdout);

    cin >> n >> k;
    double l = 100000.0, r = -100000.0;
    a[0] = 0;
    for (int i = 1; i <= n; i++) { 
        cin >> a[i];
        // l = min(l, (double)a[i]);
        // r = max(r, (double)a[i]);
    }
    l = -100000; r = 100000;
    double res = 0;
    while (abs(r-l) > eps) {
        double mid = (l+r)/2;
        if (check(mid)) {
            res = mid;
            l = mid + eps;
        }
        else r = mid - eps;
    }
    
    printf("%.5f", res);

    return 0;
}