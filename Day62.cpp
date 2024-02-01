class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack <int> st;
        for(int i=temperatures.size()-1;i>=0;i--){
            if(st.empty()){
                st.push(i);
                ans[i] = 0;
            }
            else{
                while(!st.empty() && temperatures[i]>=temperatures[st.top()]){
                    st.pop();
                }
                if(st.empty()){
                    ans[i] = 0;
                }
                // Calculate the wormer day
                else{
                    ans[i] = st.top()-i;
                }
                st.push(i);
            }
            
        }
        return ans;
    }
};