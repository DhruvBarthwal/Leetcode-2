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
pair <int,int> solve(TreeNode* root){
    //base case
    if(!root) return {0,0};

    auto l = solve(root->left);
    auto r = solve(root->right);

    int take = root->val + l.second + r.second;
    int skip = max(l.first,l.second) + max(r.first,r.second);

    return {take,skip};
}
    int rob(TreeNode* root) {
        auto ans = solve(root);
        return max(ans.first, ans.second);
    }
};