class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int size = 0;

        for(int i : nums){
            int a =0;
            int b= size;
            while(a != b){
                int mid = (a+b)/2;
                if(ans[mid] < i){
                    a = mid+1;
                }
                else{
                    b = mid;
                }
            }
            ans[a] = i;
            if(a == size){
                ++size;
            }
        }
        return size;
    }
};