# Remove Duplicate Letters

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given a string `s`, remove duplicate letters so that every letter appears once and only once. The relative order of the letters that were not removed must be preserved. You must make sure your result is  **the smallest in lexicographical order**  among all possible results.

 

 **Example 1:** 

```
Input: s = "bcabc"
Output: "abc"

```

 **Example 2:** 

```
Input: s = "cbacdcbc"
Output: "acdb"

```

 

 **Constraints:** 

- 1 <= s.length <= 104
- s consists of lowercase English letters.

 

 **Note:**  This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

## Solution

**Language:** C++  
**Runtime:** 3 ms (beats 15.33%)  
**Memory:** 9.5 MB (beats 33.82%)  
**Submitted:** 2026-10-31T10:49:03.752Z  

```cpp
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
```

---

[View on LeetCode](https://leetcode.com/problems/remove-duplicate-letters/)