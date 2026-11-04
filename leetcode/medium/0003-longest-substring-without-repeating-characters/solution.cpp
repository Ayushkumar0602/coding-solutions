class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            // If we find a duplicate, shrink window from the left
            while (seen.count(s[right])) {
                seen.erase(s[left]);
                left++;
            }

            // Add current character
            seen.insert(s[right]);

            // Update maximum length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};