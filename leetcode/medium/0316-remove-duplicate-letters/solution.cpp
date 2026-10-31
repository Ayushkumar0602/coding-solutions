class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> freq;
        unordered_set<char> seen;
        string ans = "";

        for (char c : s) freq[c]++;

        for (char c : s) {
            freq[c]--;

            if (seen.count(c)) continue;

            while (!ans.empty() && ans.back() > c && freq[ans.back()] > 0) {
                seen.erase(ans.back());
                ans.pop_back();
            }

            ans += c;
            seen.insert(c);
        }

        return ans;
    }
};