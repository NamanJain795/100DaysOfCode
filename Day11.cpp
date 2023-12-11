class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int temp = arr.size() / 4;
        for(int i=0; i < arr.size() - temp; i++){
            if(arr[i] == arr[i+temp]){
                return arr[i];
            }
        }
        return -1;
    }
};