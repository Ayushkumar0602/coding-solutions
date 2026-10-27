# Smallest Sufficient Team

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

In a project, you have a list of required skills `req_skills`, and a list of people. The `ith` person `people[i]` contains a list of skills that the person has.

Consider a sufficient team: a set of people such that for every required skill in `req_skills`, there is at least one person in the team who has that skill. We can represent these teams by the index of each person.

- For example, team = [0, 1, 3] represents the people with skills people[0], people[1], and people[3].

Return  *any sufficient team of the smallest possible size, represented by the index of each person*. You may return the answer in  **any order**.

It is  **guaranteed**  an answer exists.

 

 **Example 1:** 

```
Input: req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
Output: [0,2]

```

 **Example 2:** 

```
Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"], people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
Output: [1,2]

```

 

 **Constraints:** 

- 1 <= req_skills.length <= 16
- 1 <= req_skills[i].length <= 16
- req_skills[i] consists of lowercase English letters.
- All the strings of req_skills are unique.
- 1 <= people.length <= 60
- 0 <= people[i].length <= 16
- 1 <= people[i][j].length <= 16
- people[i][j] consists of lowercase English letters.
- All the strings of people[i] are unique.
- Every skill in people[i] is a skill in req_skills.
- It is guaranteed a sufficient team exists.

## Solution

**Language:** C++  
**Runtime:** 32 ms (beats 74.31%)  
**Memory:** 13.7 MB (beats 80.65%)  
**Submitted:** 2026-10-27T16:07:39.531Z  

```cpp
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = people.size(), m = req_skills.size();
        unordered_map<string, int> skillId;
        for (int i = 0; i < m; i++) {
            skillId[req_skills[i]] = i;
        }
        vector<int> skillsMaskOfPerson(n);
        vector<long long> dp(1 << m, -1);
        for (int i = 0; i < n; i++) {
            for (string skill : people[i]) {
                skillsMaskOfPerson[i] |= 1 << skillId[skill];
            }
        }
        function<long long(int)> f = [&](int skillsMask) -> long long {
            if (skillsMask == 0) {
                return 0;
            }
            if (dp[skillsMask] != -1) {
                return dp[skillsMask];
            }
            for (int i = 0; i < n; i++) {
                int smallerSkillsMask = skillsMask & ~skillsMaskOfPerson[i];
                if (smallerSkillsMask != skillsMask) {
                    long long peopleMask = f(smallerSkillsMask) | (1LL << i);
                    if (dp[skillsMask] == -1 || __builtin_popcountll(peopleMask) <
                                                    __builtin_popcountll(dp[skillsMask])) {
                        dp[skillsMask] = peopleMask;
                    }
                }
            }
            return dp[skillsMask];
        };
        long long answerMask = f((1 << m) - 1);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if ((answerMask >> i) & 1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/smallest-sufficient-team/)