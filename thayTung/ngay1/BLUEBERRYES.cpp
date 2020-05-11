{
    cin >> n >> k;
    ans = (n+k-1) / k;
    if (n != k && n < 2*k) ans++;
}