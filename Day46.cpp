class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> mp;
        for(int i=0;i<matches.size();i++){
            int loss=matches[i][1];
            mp[loss]++;
        }
        vector<int>ans1;
        vector<int>ans2;
        for(int i=0;i<matches.size();i++){
           int win=matches[i][0];
           int loss=matches[i][1];
           if(mp.find(win)==mp.end()) {
               ans1.push_back(win);
               mp[win]=2;

           }
           if(mp[loss]==1)
           ans2.push_back(loss);

        }
        sort(ans1.begin(),ans1.end());    
        sort(ans2.begin(),ans2.end());

        return {ans1,ans2};



        
    }
};