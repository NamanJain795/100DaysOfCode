class Solution {
public:
    int solve(vector<int>& a, vector<int>& b){
        int x = abs(a[0] - b[0]);
        int y = abs(a[1] - b[1]);

        return max(x, y);
    }
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;
        for(int i=1;i<points.size();i++){
            time += solve(points[i-1], points[i]);
        }
        return time;
    }
};