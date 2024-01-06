class Solution {
public:
    int binarySearch(vector<pair<int, pair<int, int>>>& job, int index) {
        int low = 0, high = index - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (job[mid].first <= job[index].second.first) {
                if (job[mid + 1].first <= job[index].second.first) {
                    low = mid + 1;
                } 
                else {
                    return mid;
                }
            } 
            else {
                high = mid - 1;
            }
        }   
        return -1;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<pair<int, pair<int, int>>> job;
            for (int i = 0; i < n; i++) {
                job.push_back({endTime[i], {startTime[i], profit[i]}});
        }   
        sort(job.begin(), job.end());
        vector<int> d(n, 0);
        d[0] = job[0].second.second;

        for (int i = 1; i < n; i++) {
            int currentProfit = job[i].second.second;
            int prevCompatibleJobIndex = binarySearch(job, i);

            if (prevCompatibleJobIndex != -1) {
                currentProfit += d[prevCompatibleJobIndex];
            }
            d[i] = max(d[i - 1], currentProfit);
        }
        return d[n - 1];
    }
};