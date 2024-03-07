class Solution {
public:
    int minimumLength(string s) {
        int start = 0;
        int end = s.size() - 1;
        
        while(start < end && s[start] == s[end]){
            char temp = s[start];
            while (start <= end && s[start] == temp) {
                start++;
            }
            while (end >= start && s[end] == temp) {
                end--;
            }
        }
        return end - start + 1;
    }
};