class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusted(n+1, 0);
        for(auto i : trust){
            trusted[i[0]]--;
            trusted[i[1]]++;
        }
        int ans = -1;
        for(int i=1;i<=n;i++){
            if(trusted[i] == n-1){
                ans = i;
            }
        }
        return ans;
    }
};