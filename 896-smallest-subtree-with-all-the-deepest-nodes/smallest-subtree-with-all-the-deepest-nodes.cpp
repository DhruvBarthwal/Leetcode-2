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
pair<TreeNode*, int> solve(TreeNode* root, int level){
    //base case
    if(!root) return {root,level};
    
    pair<TreeNode*,int> leftNode = solve(root->left,level+1);
    pair<TreeNode*, int> rightNode = solve(root->right,level+1);
    if(leftNode.second == rightNode.second) return {root,leftNode.second};
    if(leftNode.second > rightNode.second) return leftNode;
    else return rightNode;
}
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        pair<TreeNode*,int> ans = solve(root,0);
        return ans.first;
    }
};