class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long temp = 0;
        long long ans = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < temp){
                ans = nums[i] + temp;
            }
            temp += nums[i];
        }
        return ans;
    }
};