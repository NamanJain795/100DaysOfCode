class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        for(int i=0;i<paths.size();i++){
            string temp = paths[i][1];
            bool ans = true;
            for(int j=0;j<paths.size();j++){
                if(paths[j][0] == temp){
                    ans = false;
                    break;
                }
            }
            if(ans){
                return temp;
            }
        }   
        return "";
    }
};