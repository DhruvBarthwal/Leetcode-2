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

map<int,int> mp;

void solve(TreeNode* root, int idx){
    if(!root){
        return;
    }
    mp[idx] += root->val;
    solve(root->left,idx+1);
    solve(root->right,idx+1);
}

    int maxLevelSum(TreeNode* root) {
        solve(root,1);
        int ans = 0;
        int maxi = INT_MIN;
        for(auto [level,sum] : mp){
            if(maxi < sum){
                maxi = sum;
                ans = level;
            }
        }
        return ans;
    }
};