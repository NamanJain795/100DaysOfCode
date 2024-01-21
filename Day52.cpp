class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return nums[0];
        }
        if(n == 2){
            return max(nums[0], nums[1]);
        }

        vector<int> temp(n,0);
        temp[0] = nums[0];
        temp[1] = max(nums[0], nums[1]);

        for(int i=2;i<n;i++){
            temp[i] = max(temp[i-1], temp[i-2] + nums[i]);
        }
        return temp[n-1];
    }
};