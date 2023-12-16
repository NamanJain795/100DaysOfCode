class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        int size = s.size();
        int tize = t.size();

        if(size != tize){
            return false;
        }
        for(int i=0;i<size;i++){
            mp[s[i]]++;
            mp[t[i]]++;
        }
        for(int i=0;i<size;i++){
            mp[s[i]] -= 2;
        }
        for(auto i : mp){
            if(i.second != 0){
                return false;
            }
        }
        return true;
    }
};