class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1){
            return nums;
        }
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        vector<int> temp(n, -1);
        int maxi = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    temp[i] = j;
                }
            }
            if(dp[i] > dp[maxi]){
                maxi = i;
            }
        }
        vector<int> ans;
        while(maxi != -1){
            ans.push_back(nums[maxi]);
            maxi = temp[maxi];
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};