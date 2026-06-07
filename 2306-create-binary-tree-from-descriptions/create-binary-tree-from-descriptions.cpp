/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> node;
        unordered_set<int> child;
        for (auto& it : descriptions) {
            int p = it[0], c = it[1], flag = it[2];
            if (!node[p])
                node[p] = new TreeNode(p);
            if (!node[c])
                node[c] = new TreeNode(c);

            child.insert(c);
            if (flag == 1)
                node[p]->left = node[c];
            else
                node[p]->right = node[c];
        }
        for (auto& it : descriptions) {
            if (!child.count(it[0]))
                return node[it[0]];
        }
        return nullptr;
    }
};