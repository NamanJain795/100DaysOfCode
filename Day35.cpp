class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i : nums){
            m[i]++;
        }
        int ans = 0;

        for(auto &j : m){
            int i = j.second;

            if(i == 1){
                return -1;
            }
            ans += (i+2) / 3;
        }
        return ans;
    }
};