#include <bits/stdc++.h>
using namespace std;

const double eps = 0.0000001;
set<double> ng;

int pt_2(int x, int y, int z) {
    double a = (double)x, b = (double)y, c = (double)z;
    if (a == 0.0) {
        if (b == 0.0) { if (c == 0.0) return 0; }
        else ng.insert((double)(-c/b));
    }
    else {
        double delta = double(b*b - 4.0*a*c);
        if (delta < 0.0) return 1;
        delta = (double)sqrt(delta);
        double x1 = (double)(-b + delta)/(2.0*a);
        double x2 = (double)(-b - delta)/(2.0*a);
        ng.insert(x1);
        ng.insert(x2);
    }
    return 1;
}


int main()
{
    // freopen("input.txt", "r", stdin);
    freopen("equa.inp", "r", stdin);
    freopen("equa.out", "w", stdout);

    int n;
    cin >> n;
    int a, b, c;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c;
        if (!pt_2(a, b, c)) {cout << "-1"; return 0;}
    }

    // sort(ng.begin(), ng.end());
    // for (int i = 1; i < ng.size()  && (ng.size() > 1); i++)
    //     if (ng[i] - ng[i-1] < eps) {ng.erase(ng.begin()+i); i--;}
    
    cout << ng.size();


    return 0;
}