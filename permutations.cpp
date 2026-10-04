void solve() {
    string alf; cin >> alf;
    vector<string> valf;
    for (char c: alf) valf.push_back(string(1, c));       
    sort(valf.begin(), valf.end());

    vector<string> permutations;
    do {
        string temp = "";
        for (string e: valf) temp += e;
        permutations.push_back(temp);
    } while (next_permutation(valf.begin(), valf.end()));

    cout << permutations.size() << '\n';
    for (auto &text: permutations) cout << text << '\n';
}
