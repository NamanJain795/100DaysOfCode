class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> ans(n, 0);
        vector<long long> times(n, 0);
        sort(meetings.begin(), meetings.end());
        int m = meetings.size();
        for(int i=0;i<m;i++){
            int s = meetings[i][0];
            int e = meetings[i][1];
            bool temp = false;
            int minid = -1;
            long long val = 1e18;
            for(int j=0;j<n;j++){
                if(times[j] < val){
                    val = times[j];
                    minid = j;
                }
                if(times[j] <= s){
                    temp = true;
                    ans[j]++;
                    times[j] = e;
                    break;
                }
            }
            if(!temp){
                ans[minid]++;
                times[minid] += (1ll*(e-s));
            }
        }
        int maxi = -1;
        int id = -1;
        for(int i=0;i<n;i++){
            if(ans[i] > maxi){
                maxi = ans[i];
                id = i;
            }
        }
        return id;
    }
};