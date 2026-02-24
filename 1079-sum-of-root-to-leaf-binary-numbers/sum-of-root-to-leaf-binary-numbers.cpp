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
    int sumRootToLeaf(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        int sum = 0;
        q.push({root,0});
        while(!q.empty()){
            auto [x,curr] = q.front();
            q.pop();

            curr = (curr << 1) | (x -> val);

            if(!x->left && !x->right) sum += curr;

            if(x->left) q.push({x->left, curr});
            if(x->right) q.push({x->right, curr});
        }
        return sum;
    }
};