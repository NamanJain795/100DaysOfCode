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
    int ans = 0;
    int solve(TreeNode* root, int start){
        int d= 0;
        if(root == NULL){
            return d;
        }

        int ld = solve(root -> left, start);
        int rd = solve(root -> right, start);

        if(root -> val == start){
            ans = max(ld, rd);
            d = -1;
        }
        else if(ld >= 0 && rd >= 0){
            d = max(ld, rd) + 1;
        }
        else{
            int dis = abs(ld) + abs(rd);
            ans = max(ans, dis);
            d = min(ld, rd) - 1;
        }
        return d;

    }
    int amountOfTime(TreeNode* root, int start) {
        solve(root, start);
        return ans;
    }
};