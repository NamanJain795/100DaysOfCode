class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int i = 0;
        int j = 0;

        while(i < neededTime.size() && j < neededTime.size()){
            int total = 0;
            int maxi = 0;

            while(j < neededTime.size() && colors[i] == colors[j]){
                total += neededTime[j];
                maxi = max(maxi, neededTime[j]);
                j++;
            }
            ans += total - maxi;
            i = j;
        }
        return ans;
    }
};