class Solution {
public:
    int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        long long int ans = 0;
        for(int i=0;i<arr.size();i++){
            int r = 0;
            int l = 0;
            long long int temp = 0;
            int j = i;
            while(j<arr.size() && arr[j] >= arr[i]){
                r++;
                j++;
            }
            temp = temp+(arr[i]*r);
            ans += temp;
            j=i-1;
            while(j >= 0 && arr[j] > arr[i]){
                l++;
                j--;
            }
            ans += (l*temp);
            ans = ans%mod;
        }
        return ans;
    }
};