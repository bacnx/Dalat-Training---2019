#include <bits/stdc++.h>
using namespace std;

const int maxn = 110;

// vector<int> yes, no;
int n, k, l[maxn], r[maxn];
int xet[maxn];

void sub1() {
    int a, b, c, d;
    for (int i = 1; i <= k; i++) {
        cin >> a >> b >> c >> d;
        if (d == 1) {cout << c; return ;}
        if (d == 2) {cout << b; return ;} 
    }
    cout << 0;
}

void sub2() {
    for (int i = 1; i <= n; i++) xet[i] = -1;

    int s, kq;
    for (int i = 1; i <= k; i++) {
        cin >> s;
        for (int j = 1; j <= s; j++) cin >> l[j];
        for (int j = 1; j <= s; j++) cin >> r[j];
        cin >> kq;

        if (kq == 0) {
            for (int j = 1; j <= s; j++) {
                xet[l[j]] = 1;
                xet[r[j]] = 1;
            }
        }
        else if (kq == 1) {
            for (int j = 1; j <= s; j++) {
                xet[l[j]] = 1;
                if (xet[r[j]] == -1) xet[r[j]] = 0;
            }
        }
        else {
            for (int j = 1; j <= s; j++) {
                if (xet[l[j]] == -1) xet[l[j]] = 0;
                xet[r[j]] = 1;
            }
        }
    }

    int cs1, cs2, cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++)
        if (xet[i] == 0) {cs1 = i; cnt1++;}
        else {cs2 = i; cnt2++;}
    
    if (cnt1 == 1) cout << cs1;
    else if (cnt1 == 0 && cnt2 == 1) cout << cs2;
    else cout << 0;
}

void sub3() {

}

int main()
{
    // freopen("input.txt", "r", stdin);
    freopen("fcoin.inp", "r", stdin);
    freopen("fcoin.out", "w", stdout);

    cin >> n >> k;
    if (n <= 100) sub2();
    else cout << "0";

    return 0;
}