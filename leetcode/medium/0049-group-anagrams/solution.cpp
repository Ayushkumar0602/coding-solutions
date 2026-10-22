#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (auto &s : strs) {
            string key = s;
            sort(key.begin(), key.end());   // sort each string to form a key
            mp[key].push_back(s);           // group anagrams under same key
        }

        vector<vector<string>> result;
        for (auto &p : mp) 
            result.push_back(p.second);

        return result;
    }
};
