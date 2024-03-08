class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        int maxFreq = INT_MIN;
        for(auto i : freq){
            maxFreq = max(maxFreq, i.second);
        }
        int noOfMaxFreqElement = 0;
        for(auto i : freq){
            if(i.second == maxFreq){
                noOfMaxFreqElement++;
            }
        }
        return maxFreq * noOfMaxFreqElement;
    }
};