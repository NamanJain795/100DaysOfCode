class Solution {
public:
    unordered_map<int, vector<int>> pi;
    unordered_map<int, vector<int>> ip;
    void dfs(int index, vector<int>& Index, unordered_map<int,bool>& Prime){
        if(Index[index] == true) return;
        Index[index] = true;

        for(auto &prime : ip[index]){
            if(Prime[prime] == true) 
                continue;
            Prime[prime] = true;
            for(auto &index1 : pi[prime]){
                if(Index[index1] == true) continue;
                dfs(index1, Index, Prime);
            }
        }
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n; i++) {
            int temp = nums[i];
            for (int j = 2; j*j <= nums[i]; j++) {
                if (temp % j == 0) {
                    pi[j].push_back(i);
                    ip[i].push_back(j);
                    while (temp % j == 0)
                      temp /= j;
                }
            }
            if (temp > 1) {
                pi[temp].push_back(i);
                ip[i].push_back(temp);
            }
        }

        vector<int> Index(nums.size(),0);
        unordered_map<int,bool> Prime;
        dfs(0, Index, Prime);     

        for(int i=0; i<Index.size(); i++) 
            if(Index[i] == false) 
                return false;
        return true;        
    }
};