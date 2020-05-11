#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int sum5[100001];
bool nt[140];
int cp[10000001];

void init_sum5() {
    sum5[0] = 0;
    for (int i = 1; i <= 1e5; i++)
        if (i % 10 == 0) sum5[i] = sum5[i/10];
        else sum5[i] = sum5[i-1] + 1;
}

void init_nt() {
    for (int i = 2; i < 140; i++) nt[i] = true;

    for (int i = 2; i < 140; i++)
        if (nt[i])
            for (int j = 2; j*i <= 140; j++)
                nt[i*j] = false;
}

int scs(ll x) {
    int result = 0;
    while (x != 0) {
        result += sum5[x % 100000];
        x /= 100000;
    }
    return result;
}

void init_cp() {
    cp[0] = 0;
    for (ll i = 1; i <= 10000000; i++)
        if (nt[scs(i*i)]) cp[i] = cp[i-1] + 1;
        else cp[i] = cp[i-1];
}

int main()
{
    // freopen("input.txt", "r", stdin);
    
    init_nt();
    init_sum5();
    init_cp();
    

    return 0;
}