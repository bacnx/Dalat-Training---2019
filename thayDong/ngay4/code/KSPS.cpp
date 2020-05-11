#include <bits/stdc++.h>
using namespace std;

string xau(int x) {
    if (x == 0) return "0";
    string res;
    while (x != 0) {
        res = (char)(x % 10 + 48) + res;
        x /= 10;
    }
    return res;
}

string thap_phan(int m, int n) {
    string res;
    res = xau(m/n);
    m %= n;
    for (int i = 1; i <= 2000006; i++) {
        m = m * 10;
        res += (char)(m/n + 48);
        m = m % n;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
    freopen("ksps.inp", "r", stdin);
    freopen("ksps.out", "w", stdout);

    int m, n;
    cin >> m >> n;
    string x;
    cin >> x;
    string s = thap_phan(m, n);

    cout << s.find(x) + 1;

    return 0;
}