#include <bits/stdc++.h>
using namespace std;

const int maxn = 300050;

int n, h;
int x1[maxn], x2[maxn];
int t[maxn], xmax[maxn];

int f(int k) {
    int x = 0, y = h;
    for (int i = 1; i <= n; i++) {
        x += x2[i] - x1[i];
        int kc = x1[i+1] - x2[i];
        if (y > kc) {
            x += kc;
            y -= kc;
        } else break;
    }
    x += y;
    return x;
}

int main()
{
    freopen("input.txt", "r", stdin);

    cin >> n >> h;
    t[1] = xmax[1] = 0;
    cin >> x1[1] >> x2[1];
    for (int i = 2; i <= n; i++) {
        cin >> x1[i] >> x2[i];
        t[i] = t[i-1] + x1[i] - x2[i-1];
        xmax[i] = xmax[i-1] + 
    }
    

    return 0;
}