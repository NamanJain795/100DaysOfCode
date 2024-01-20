class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix[0].size();
        int n = matrix.size();
        vector<vector<int>> ans(n, vector<int>(m,0));

        for(int i=0;i<m;i++){
            ans[0][i] = matrix[0][i];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int x = INT_MAX;
                int y = INT_MAX;
                int z = matrix[i][j] + ans[i-1][j];

                if(j-1 >= 0){
                    x = matrix[i][j] + ans[i-1][j-1];
                }
                if(j+1 < m){
                    y = matrix[i][j] + ans[i-1][j+1];
                }
                ans[i][j] = min(z, min(x,y));
            }
        }
        int mini = ans[n-1][0];

        for(int i = 1;i<m;i++){
            mini = min(mini, ans[n-1][i]);
        }
        return mini;
    }
};