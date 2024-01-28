class Solution {
public:
    int mod = 1e9+7;
    vector<vector<vector<int>>> dp;
    int solve(int n, int m, int maxMove, int startRow, int startColumn){
        if(startColumn < 0 || startColumn >= n || startRow < 0 || startRow >= m){
            return 1;
        }
        if(maxMove == 0){
            return 0;
        }
        if(dp[startRow][startColumn][maxMove] != -1){
            return dp[startRow][startColumn][maxMove];
        }
        int u = solve(n, m, maxMove-1, startRow-1, startColumn);
        int d = solve(n, m, maxMove-1, startRow+1, startColumn);    
        int l = solve(n, m, maxMove-1, startRow, startColumn-1);
        int r = solve(n, m, maxMove-1, startRow, startColumn+1);
        
        return dp[startRow][startColumn][maxMove] = ((u+d)%mod + (l+r) % mod) % mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(maxMove+1,-1)));
        return solve(n, m, maxMove, startRow, startColumn);
    }
};