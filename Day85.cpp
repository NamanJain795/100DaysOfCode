class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto i : flights){
            adj[i[0]].push_back({i[1], i[2]});
        }
        vector<int> distances(n, INT_MAX);
        distances[src] = 0;

        queue<pair<int, int>> q;
        q.push({src, 0});
        int s = 0;

        while(!q.empty() && s <= k){
            int size1 = q.size();
            while(size1-- > 0){
                auto [des, distance] = q.front();
                q.pop();

                if(!adj.count(des)){
                    continue;
                }
                for (auto& [neighbour, price] : adj[des]) {
                    if (price + distance >= distances[neighbour]) {continue;}
                    distances[neighbour] = price + distance;
                    q.push({neighbour, distances[neighbour]});
                }
            }
            s++;
        }
        if(distances[dst] != INT_MAX){
            return distances[dst];
        }
        return -1;
    }
};