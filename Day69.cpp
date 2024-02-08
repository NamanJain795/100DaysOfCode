class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> temp;
        unordered_map<char, int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(auto i : mp){
            temp.push_back({i.second, i.first});
        }
        sort(temp.rbegin(), temp.rend());

        string ans;

        for(auto i : temp){
            for(int j=0;j<i.first;j++){
                ans += i.second;
            }
        }
        return ans;
    }
};