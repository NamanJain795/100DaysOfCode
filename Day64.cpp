class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=1;i<=9;i++){
            int no = i;
            int nextelement = i+1;
            while(no <= high && nextelement <= 9){
                no = no*10 + nextelement;
                if(no >= low && no <= high){
                    ans.push_back(no);
                }
                nextelement++;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};