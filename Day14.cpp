class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> row(m);
        vector<int> col(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                row[i] += grid[i][j];
                col[j] += grid[i][j];
            }
        }
        vector<vector<int>> diff(m, vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                diff[i][j] = row[i] + col[j] - (n-row[i]) - (m-col[j]);
            }
        }
        return diff;
    }
};