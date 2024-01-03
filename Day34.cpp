class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        vector<int> v;
        for(auto i : bank){
            string temp = i;
            int count = 0;
            for(int j=0;j<temp.size();j++){
                if(temp[j] == '1'){
                    count++;
                }
            }
            if(count != 0){
                v.push_back(count);
            }
        }
        for(int i=1;i<v.size();i++){
            int A = v[i]*v[i-1];
            ans += A; 
        }
        return ans;
    }
};