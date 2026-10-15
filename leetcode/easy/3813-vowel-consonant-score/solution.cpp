class Solution {
public:
    int vowelConsonantScore(string s) {
        unordered_map<char, int> mp;
        mp['a']++;
        mp['e']++;
        mp['i']++;
        mp['o']++;
        mp['u']++;

        int vowel = 0;
        int cons = 0;

        for (int i = 0; i < s.size(); i++) {
            if (mp.find(s[i]) != mp.end()) {
                vowel++;
            } else if (s[i] >= 'a' && s[i] <= 'z') {
                cons++;
            }
        }

        if (cons > 0) {
            int score=floor(vowel / cons);
            return score;
        }

        return 0;
    }
};