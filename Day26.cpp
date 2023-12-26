class Solution {
public:
    const int mod = (int)pow(10, 9) + 7;
    int solve(vector<vector<int>>& temp, int n, int k, int target){
        if(n == 0 && target == 0){
            return 1;
        }
        if(n == 0 || target <= 0){
            return 0;
        }
        if(temp[n][target] != -1){
            return temp[n][target] % mod;
        }
        int ans = 0;
        for(int i = 1; i <= k; i++){
            ans = (ans + solve(temp, n-1, k, target - i)) % mod;
        }
        temp[n][target] = ans % mod;
        return temp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> temp(n+1, vector<int>(target + 1, -1));
        return solve(temp, n, k, target);
    }
};