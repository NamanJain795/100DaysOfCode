class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> canKnow(n);  
        canKnow[0] = canKnow[firstPerson] = true;  

        map<int, vector<pair<int, int>>> mp;  
        for (auto& i : meetings) 
            mp[i[2]].emplace_back(i[0], i[1]); 

        for (auto& [k, v] : mp) {
            unordered_map<int, vector<int>> g;  
            unordered_set<int> st;  

            for (auto& [x, y] : v) {
                g[x].push_back(y); 
                g[y].push_back(x); 
                if (canKnow[x]) st.insert(x); 
                if (canKnow[y]) st.insert(y); 
            }

            queue<int> q; 
            for (auto& x : st) q.push(x); 
         
            while (q.size()) {
                auto x = q.front(); q.pop(); 
                for (auto& y : g[x]) 
                    if (!canKnow[y]) {
                        canKnow[y] = true; 
                        q.push(y); 
                    }
            }
        }
        
        vector<int> ans; 
        for (int i = 0; i < n; ++i) 
            if (canKnow[i]) ans.push_back(i); 

        return ans; 
    }
};