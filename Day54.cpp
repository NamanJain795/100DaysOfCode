class Solution {
public:
    void solve(vector<string> &arr, string curr, int s, int &ans){
        if(ans < curr.length()){
            ans = curr.length();
        }
        for(int i=s;i<arr.size();i++){
            if(!valid(curr, arr[i])){
                continue;
            }
            solve(arr, curr + arr[i], i+1, ans);
        }
    }

    bool valid(string &currStr, string &n){
        unordered_set<char> st;

        for(char c : n){
            if(st.count(c) > 0){
                return false;
            }
            st.insert(c);
            if(currStr.find(c) != string::npos){
                return false;
            }
        }
        return true;
    }
    int maxLength(vector<string>& arr) {
        // int n = arr.size();
        // if(n == 1){
        //     return arr[0].length();
        // }
        int ans = 0;
        solve(arr, "", 0, ans);
        return ans;
    }
};