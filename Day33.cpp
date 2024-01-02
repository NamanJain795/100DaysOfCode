class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> m;
        int mx = 0;
        for(auto i : nums){
            m[i]++;
        }
        for(auto i : m){
            mx = max(mx, i.second);
        }

        for(int i=0;i<mx;i++){
            vector<int> temp;
            for(auto &i : m){
                if(i.second > 0){
                    temp.push_back(i.first);
                    i.second--;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};