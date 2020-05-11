#include <bits/stdc++.h>
using namespace std;

struct pheptrao { int i, m, j; };

int undo(pheptrao s, int p) {
	int i = s.i, m = s.m, j = s.j;
	if (p >= j && p <  j + m)
		return p + i - j;
	else if (p >= min(i, j) && p < max(i, j) + m)
		if (p < j) return p + m;
		else return p - m;
	return p;
}

int n, k, x;
pheptrao s[100005];

int main()
{
	freopen("shuffle.inp", "r", stdin);
	freopen("shuffle.out", "w", stdout);

	cin >> n >> k >> x;
	for (int i = 1; i <= x; i++)
		cin >> s[i].i >> s[i].m >> s[i].j;

	for (int i = 1; i <= k; i++) {
		int p = i;
		for (int j = x; j > 0; j--)
			p = undo(s[j], p);
		cout << p << " ";
	}

	return 0;
}