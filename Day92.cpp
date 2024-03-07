class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.size();
        sort(s.rbegin(), s.rend());
        for(int i=n-1;i>=0;i--){
            if(s[i] == '1'){
                swap(s[i], s[n-1]);
            }
        }
        return s;
    }
};