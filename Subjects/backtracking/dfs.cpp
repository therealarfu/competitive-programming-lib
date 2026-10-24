// Letter Combinations of a Phone Number
class Solution {
public:
    vector<string> ans;
    string path;
    string mapa[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void bt (string &digits, int idx) {
        if (idx == digits.size()) {
            ans.push_back(path);
            return;
        }

        string mapa_word = mapa[digits[idx] - '0'];
        for (char c: mapa_word) {
            path.push_back(c);
            bt(digits, idx + 1);
            path.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return ans;
        bt(digits, 0);
        return ans;
    }
};
