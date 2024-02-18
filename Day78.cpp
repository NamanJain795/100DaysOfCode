class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        vector<int> temp;
        for(auto i : mp){
            temp.push_back(i.second);
        }
        int x = 0;
        sort(temp.begin(),  temp.end());
        for(int i=0;i<temp.size();i++){
            x += temp[i];
            if(x > k){
                return temp.size() - i;
            }
        }
        return 0;
    }
};