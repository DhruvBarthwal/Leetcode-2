/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //creation of tree to graph
        if(!root){
            return {};
        }
        unordered_map<int,list<int>> graph;
        queue<TreeNode*>Q;
        Q.push(root);
        while(!Q.empty()){
            TreeNode* node = Q.front();
            Q.pop();

            if(node->left){
                graph[node->val].push_back(node->left->val);
                graph[node->left->val].push_back(node->val);
                Q.push(node->left);
            }
            if(node->right){
                graph[node->val].push_back(node->right->val);
                graph[node->right->val].push_back(node->val);
                Q.push(node->right);
            }
        }
        vector<int> result;
        unordered_set<int> vis;
        queue<pair<int,int>> q;
        q.push({target->val,0});
        vis.insert(target->val);
        while(!q.empty()){
            auto [node, dist] = q.front();
            q.pop();

            if(dist == k){
                result.push_back(node);
            }
            if(dist>=k){
                continue;
            }
            for(int nei : graph[node]){
                if(!vis.count(nei)){
                    vis.insert(nei);
                    q.push({nei, dist+1});
                }
            }
        }
        return result;
    }
};