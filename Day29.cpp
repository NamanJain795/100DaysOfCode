class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int job = jobDifficulty.size();

        if(job < d){
            return -1;
        }

        vector<vector<int>> temp(d, vector<int>(job, 0));

        temp[0][0] = jobDifficulty[0];
        for(int i=1;i<job;i++){
            temp[0][i] = max(temp[0][i-1], jobDifficulty[i]);
        }

        for(int days = 1;days < d;days++){
            for(int i=days;i<job;i++){
                int maxi = jobDifficulty[i];
                temp[days][i] = INT_MAX;  

                for(int j=i;j>=days;j--){
                    maxi = max(maxi, jobDifficulty[j]);
                    temp[days][i] = min(temp[days][i],temp[days-1][j-1] + maxi);
                } 
            }
        }
        return temp[d-1][job-1];
    }
};