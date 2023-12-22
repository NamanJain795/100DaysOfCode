class Solution {
public:
    int maxScore(string s) {
        int ans = 0;
        int countzero = 0;
        int countone = count(s.begin(), s.end(), '1');

        for(int i=0;i<s.size()-1;i++){
            if(s[i] == '0'){
                countzero++;
            }
            else{
                countone--;
            }
            ans = max(ans, countzero + countone);
        }
        return ans;
    }
};