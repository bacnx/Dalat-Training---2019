#include <bits/stdc++.h>
using namespace std;

const int maxn = 200050;
const int base = 31;

int POW[maxn];

string s;
int n;
int a[maxn], h[maxn], hch[maxn*2];
vector<int> ka;

int getHash(int i, int j, int hashP[]) {
    return hashP[j] - hashP[i-1] * POW[j-i+1];
}

bool kARY(int k) {
    int l = n/k;

    hch[0] = 0;
    for (int i = 1; i <= l; i++)
        hch[i] = hch[i-1] * base + s[i]-'a'+1;
    for (int i = 1; i <= l; i++) 
        hch[i+l] = hch[i+l-1]*base + s[i]-'a'+1;

    for (int i = l+1; i <= n; i+=l) {
        int z = getHash(i, i+l-1, h);
        bool ok = false;

        for (int j = 1; j <= l; j++)
            if (z == getHash(j, j+l-1, hch)) ok = true;
        if (!ok) return false;
    }

    return true;
}

int main()
{
    freopen("strkary.inp", "r", stdin);
    freopen("strkary.out", "w", stdout);

    cin >> s;
    n = s.size();

    POW[0] = 1;
    for (int i = 1; i <= n; i++)
        POW[i] = POW[i-1] * base;

    s = " " + s;
    h[0] = 0;
    for (int i = 1; i <= n; i++)
        h[i] = h[i-1] * base + (s[i] - 'a' + 1);
    
    for (int i = 1; i*i <= n; i++)
        if (n % i == 0) {
            if (kARY(i)) ka.push_back(i);
            if (n/i != i && kARY(n/i)) ka.push_back(n/i);
        }

    sort(ka.begin(), ka.end());

    cout << ka.size() << endl;
    for (int i = 0; i < ka.size(); i++) 
        cout << ka[i] << " ";

    return 0;
}