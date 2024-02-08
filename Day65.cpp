class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for(int i=0;i<n;i++){
            int ansMax = 0;
            int ansSum = 0;
            for(int j=i;j>=max(0,i-k+1);j--){
                ansMax = max(ansMax, arr[j]);

                int cur = ansMax*(i-j+1)+dp[j];
                ansSum = max(ansSum, cur);
            }
            dp[i+1] = ansSum;
        }
        return dp[n];
    }
};