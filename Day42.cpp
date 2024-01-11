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
    int ans = 0;
    void solve(TreeNode* root, int a, int b){
        if(root == NULL){
            return;
        }
        if(!(a == INT_MAX || b == INT_MIN)){
            ans = max({ans, abs(root -> val - a), abs(root -> val - b)});
        }
        a = min(root -> val, a);
        b = max(root -> val, b);
        solve(root -> left, a, b);
        solve(root -> right, a, b);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        solve(root, INT_MAX, INT_MIN);
        return ans;
    }
};