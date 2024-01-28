class Solution {
public:
    int mod = 1000000007;
    int kInversePairs(int n, int k) {
        int dp[1001][1002] = {0};
        dp[0][0] = 1;

        for(int i=1;i<=n;i++){
            long int temp = 0;
            for(int j=0;j<=k;j++){
                temp += dp[i-1][j];
                if(j >= i){
                    temp -= dp[i-1][j-i];
                }
                dp[i][j] = temp % mod;
            }
        }
        return dp[n][k];
    }

};