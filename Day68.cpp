class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(const string& word : strs){
            string temp = word;
            sort(temp.begin(), temp.end());

            if(mp.find(temp) == mp.end()){
                mp[temp] = {word};
            }
            else{
                mp[temp].push_back(word);
            }
        } 
        vector<vector<string>> ans;
        for(const auto& ch : mp){
            ans.push_back(ch.second);
        }
        return ans;
    }
};