#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

struct knot { int key, value; };
bool cmp(const knot &a, const knot &b) { return a.value < b.value; }

int n;
knot d[maxn], l[maxn];
int pr[maxn];

int check(int k) {
	for (int i = 1; i <= k; i++)
		if ((long long)2*l[i].value*l[i].value <= (long long)d[n-k+i].value*d[n-k+i].value)
			pr[l[i].key] = d[n-k+i].key;
		else return k-1;
	for (int i = k+1; i <= n; i++)
		if (l[i].value >= d[i-k].value)
			pr[l[i].key] = d[i-k].key;
		else return k+1;
	return k;
}

int main()
{
	freopen("iq.inp", "r", stdin);
	freopen("iq.out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> l[i].value;
		l[i].key = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> d[i].value;
		d[i].key = i;
	}

	sort(l+1, l+n+1, cmp);
	sort(d+1, d+n+1, cmp);

	int l = 0, r = n, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (check(mid) < mid) r = mid - 1;
		else if (check(mid) > mid) l = mid + 1;
		else break;
	}

	for (int i = 1; i <= n; i++)
		cout << pr[i] << " ";

	return 0;
}