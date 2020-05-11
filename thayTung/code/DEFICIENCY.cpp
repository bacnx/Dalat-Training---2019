#include <bits/stdc++.h>
using namespace std;

struct knot { int key, value; };
bool cmp(const knot &a, const knot &b) {
	if (a.key == b.key) return a.value < b.value;
	return a.key < b.key; 
}

const int maxn = 1003;

int n, m, s;
knot a[maxn];

int main()
{
	freopen("deficiency.inp", "r", stdin);
	freopen("deficiency.out", "w", stdout);

	cin >> n >> m >> s;
	int d1, d2;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].value >> d1 >> d2;
		if (a[i].value >= 0) a[i].key = d2;
		else a[i].key = d1;
	}
	sort(a + 1, a + n + 1, cmp);

	for (int i = 1; i <= n; i++)
		if ((s += a[i].value) < 0) {
			cout << "YES";
			return 0;
		}
	cout << "NO";

	return 0;
}