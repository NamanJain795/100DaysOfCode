class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int s = 0;
        int maxi = 0;
        int left = 0;
        int right = tokens.size()-1;
        while(left <= right){
            if(power >= tokens[left]){
                power -= tokens[left];
                s++;
                left++;
                maxi = max(maxi, s);
            }
            else if(s > 0){
                power += tokens[right];
                s--;
                right--;
            }
            else{
                break;
            }
        }
        return maxi;
    }
};