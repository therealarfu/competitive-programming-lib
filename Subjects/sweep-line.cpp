// Restaurants
// sweep line
void solve() {
    int n; cin >> n;
    vector<pair<int, int>> arr(n, {0, 0}); for (auto &x: arr) cin >> x.first >> x.second; 

    vector<pair<int, int>> events;
    for (int i = 0; i < n; i++) {
        events.push_back({arr[i].first, 1});
    }

    for (int i = 0; i < n; i++) {
        events.push_back({arr[i].second, -1});
    }

    sort(events.begin(), events.end(), [](auto &x, auto &y) {
        if (x.first == y.first) {
            return x.second < y.second;
        }
        return x.first < y.first;
    });

    int ans = 0;
    int count = 0;

    for (int i = 0; i < 2 * n; i++) {
        count += events[i].second;
        ans = max(ans, count);
    }
    cout << ans << '\n';
}
