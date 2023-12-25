class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> ans(n+1, 0);
        ans[n] = 1;
        for(int i=n-1;i>=0;--i){
            if(s[i] != '0'){
                ans[i] += ans[i+1];
            }
            if(i+1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i+1] <= '6')){
                ans[i] += ans[i+2];
            }
        }
        return ans[0];
    }
};