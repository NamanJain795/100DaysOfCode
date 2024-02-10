class Solution {
public:
    string temp;
    int solve(int i, int j, int ans=0){
        while(i >= 0 && j < temp.size()){
            if(temp[i] == temp[j]){
                ans++;
                i--;
                j++;
            }
            else{
                break;
            }
        }
        return ans;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        temp = s;
        for(int i=0;i<n;i++){
            ans += solve(i, i);
            ans += solve(i, i+1);
        }
        return ans;
    }
};