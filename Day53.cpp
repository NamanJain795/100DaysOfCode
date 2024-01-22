class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n+1, 0);
        for(int i=0;i<n;i++){
            temp[nums[i]]++;
        }
        int d = -1;
        int m = -1;
        for(int i=0;i<temp.size();i++){
            if(temp[i] == 2){
                d = i;
            }
            if(temp[i] == 0){
                m = i;
            }
        }
        return {d, m};
    }
};