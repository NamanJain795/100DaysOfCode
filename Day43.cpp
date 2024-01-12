class Solution {
public:
    int solve(string x){
        int ans = 0;
        for(int i=0;i<x.size();i++){
            if (x[i] == 'a' || x[i] == 'e' || x[i] == 'i' || x[i] == 'o' || x[i] == 'u' || x[i] == 'A' || x[i] == 'E' || x[i] == 'I' || x[i] == 'O' || x[i] == 'U') {
                ans++;
            }
        }
        return ans;
    }
    bool halvesAreAlike(string s) {
        int n = s.size();

        string a = s.substr(0, n/2);
        string b = s.substr(n/2, n);

        int ans1 = solve(a);
        int ans2 = solve(b);

        return ans1 == ans2;
    }
};