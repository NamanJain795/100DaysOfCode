class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        vector<int> temp;
        for(int i=0;i<arr.size();i++){
            int count = 1;

            while(i+1 < arr.size() && arr[i] == arr[i+1]){
                count++;
                i++;
            }
            temp.push_back(count);
        }
        sort(temp.begin(), temp.end());

        for(int i=1;i<temp.size();i++){
            if(temp[i] == temp[i-1]){
                return false;
            }
        }
        return true;
    }
};