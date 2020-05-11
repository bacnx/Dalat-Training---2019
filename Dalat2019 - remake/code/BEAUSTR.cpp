#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5+5;

int n, k, psum[maxn], value[maxn];

int sb(int l, int r, int x) {
	int mid, ans = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (psum[mid] >= x) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

int f(int x) {
	int result = 0, c;
	for (int i = 1;; i = c+1) {
		c = sb(i, k, psum[i-1] + x);
		if (c == -1 || i > k) break;
		result += x+1;
	}
	if (result <= x+1) return 0;
	return result-1;
}

int main()
{
	freopen("beaustr.inp", "r", stdin);
	freopen("beaustr.out", "w", stdout);

	cin >> n;
	char c; int s = 0; k = 0, psum[0] = 0;
	for (int i = 0; i <= n; i++) {
		cin >> c;
		if (c == '1' || i == n) {
			value[++k] = s;
			psum[k] = psum[k-1] + s;
			s = 0;
		}
		else s++;
	}

	int ans = 0;
	for (int i = 0; i <= n; i++)
		ans = max(ans, f(i));
	cout << ans;

	return 0;
}