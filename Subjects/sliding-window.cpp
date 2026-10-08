// Balanced teams
void solve() {
    int n; cin >> n;
    vi arr(n, 0); for (auto &x: arr) cin >> x;
    sort(arr.begin(), arr.end());

    int count = 0;
    int l = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        count++;
        if (arr[i] - arr[l] > 5) {
            while (arr[i] - arr[l] > 5) {
                l++;
                count--;
            }
        }
        ans = max(ans, count);
    }
    cout << ans;
}

// Books

void solve() {
    int n, t; cin >> n >> t;
    vi arr(n, 0); for (auto &num: arr) cin >> num;
    ll soma = 0;
    int ans = 0;
    int count = 0;
    int l = 0;
    for (int i = 0; i < n; i++) {
        soma += arr[i];
        count++;
        if (soma > t) {
            while (soma > t) {
                soma -= arr[l];
                count--;
                l++;
            } 
        }
        ans = max(ans, count);
    }
    cout << ans << '\n';
}