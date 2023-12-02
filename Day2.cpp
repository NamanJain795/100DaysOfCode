class Solution {
public:
    bool solve(string& word, vector<int>& count){
        vector<int> c(26 ,0);

        for(char ch : word){
            int x = ch - 'a';
            c[x]++;
            if(c[x] > count[x]){
                return false;
            }
        }
        return true;
    }
    int countCharacters(vector<string>& words, string chars) {
        vector<int> counts(26, 0);

        for(char ch : chars){
            counts[ch - 'a']++;
        }
        int result = 0;

        for(auto word : words){
            if(solve(word, counts)){
                result += word.length();
            }
        }
        return result;
    }
};