/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void check(vector<int>& temp , int& ans){
        int cnt = 0;
        for(auto& i : temp){
            if(i % 2) {
                cnt++;
            }
        }
        if(cnt <= 1){ 
            ans++;
        }
        return;
    }
    void solve(TreeNode* root, int &ans, vector<int> &temp){
        if(!root -> left && !root -> right){
            check(temp, ans);
            return ;
        }
        if(root -> left){
            temp[root -> left -> val]++;
            solve(root -> left , ans , temp);
            temp[root -> left -> val]++;
        }
        if(root -> right){
            temp[root -> right -> val]++;
            solve(root -> right , ans , temp);
            temp[root -> right -> val]--;
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans = 0;
        vector<int> temp(10, 0);
        temp[root -> val]++;
        solve(root, ans, temp);
        return ans;
    }
};