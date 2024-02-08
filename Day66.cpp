
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) {
            return "";
        }

        unordered_map<char, int> mp;
        for (char ch : t) {
            int cnt = mp[ch];
            mp[ch] = cnt + 1;
        }

        int required = mp.size();
        int l = 0, r = 0;
        int f = 0;

        unordered_map<char, int> windowCounts;
        int ans[3] = { -1, 0, 0 };

        while (r < s.length()) {
            char c = s[r];
            int cnt = windowCounts[c];
            windowCounts[c] = cnt + 1;

            if (mp.find(c) != mp.end() && windowCounts[c] == mp[c]) {
                f++;
            }

            while (l <= r && f == required) {
                c = s[l];

                if (ans[0] == -1 || r - l + 1 < ans[0]) {
                    ans[0] = r - l + 1;
                    ans[1] = l;
                    ans[2] = r;
                }

                windowCounts[c]--;
                if (mp.find(c) != mp.end() && windowCounts[c] < mp[c]) {
                    f--;
                }

                l++;
            }

            r++;
        }

        return ans[0] == -1 ? "" : s.substr(ans[1], ans[0]);
    }
};



