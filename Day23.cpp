class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> ans;
        int x = 0;
        int y = 0;
        ans.insert({x, y});
        for(int i=0;i<path.size();i++){
            if(path[i] == 'N'){
                y++;
            }
            else if(path[i] == 'S'){
                y--;
            }
            else if(path[i] == 'E'){
                x++;
            }
            else if(path[i] == 'W'){
                x--;
            }
            if(ans.find({x,y}) != ans.end()){
                return true;
            }
            ans.insert({x, y});
        }
        return false;
    }
};