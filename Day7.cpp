class Solution {
public:
    string largestOddNumber(string num) {
        string s = "";
        int k;
        int n = num.size() - 1;
        if((num[n] - '0') % 2 != 0){
            return num;
        }      
        else{
            k = -1;
            for(int i = n;i >= 0;i--){
                if((num[i] - '0') % 2 != 0){
                    k = i;
                    break;
                }
            }
        }
        for(int i=0;i<=k;i++){
            s += num[i];
        }
        return s;
    }
};