class Solution {
public:
    int solve(vector<int> &temp, int target){
        int cnt = 0;
        int sum = 0;
        unordered_map<int, int> mp;
        for(int i=0;i<temp.size();i++){
            sum += temp[i];
            if(sum == target){
                cnt++;
            }
            if(mp.find(sum- target) != mp.end()){
                cnt += mp[sum - target];
            }
            mp[sum]++;
        }
        return cnt;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        for(int i=0;i<m;i++){
            vector<int> temp(n, 0);
            for(int j=i;j<m;j++){
                for(int k=0;k<n;k++){
                    temp[k] += matrix[j][k];
                }
                ans += solve(temp, target);
            }
        }
        return ans;
    }
};