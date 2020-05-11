#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<string> l, r;

int main()
{
    freopen("plus.inp", "r", stdin);
    freopen("plus.out", "w", stdout);
    
    ll a, b;
    cin >> a >> b;

    while (a != b) {
        int t = __gcd(a, b);
        a /= t; b /= t;
        if (a % 2 != 0 && b % 2 != 0) {
            if (a > b) { 
                l.push_back("A");
                l.push_back("B");
                r.push_back("B");
                r.push_back("B");
                a += b, b += b;
            }
            else {
                l.push_back("B");
                l.push_back("A");
                r.push_back("A");
                r.push_back("A");
                b += a, a += a;                
            }
        }
        else if (a % 2 != 0) {
            l.push_back("A");
            r.push_back("A");
            a += a;
        }
        else if (b % 2 != 0) {
            l.push_back("B");
            r.push_back("B");
            b += b;
        }
    }

    cout << l.size() << endl;
    for (int i = 0; i < l.size(); i++)
        cout << l[i] << "+=" << r[i] << endl;

    return 0;
}