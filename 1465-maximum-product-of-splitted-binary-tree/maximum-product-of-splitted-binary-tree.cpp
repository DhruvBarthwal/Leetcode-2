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
//intialization
long long totalSum =0;
long long maxProd = 0;
const int M = 1e9 + 7;
//Step 1 : Calculate total sum of tree
long long findSum(TreeNode* root){
    if(!root) return 0;
    return root->val + findSum(root->left) + findSum(root->right);
}
//Step 2 : Calculate max product
long long solve(TreeNode* root){
    if(!root) return 0;

    long long leftSum = solve(root->left);
    long long rightSum = solve(root->right);

    long long oneSubtree = root->val + leftSum + rightSum;
    long long secondSubtree = totalSum - oneSubtree;

    //calculate max product
    maxProd = max(maxProd, oneSubtree * secondSubtree);
    //returning this sum  because we are calculating one subtree while traversing
    return oneSubtree;
}
    int maxProduct(TreeNode* root) {
        totalSum = findSum(root);
        solve(root);
        return maxProd % M;
    }
};