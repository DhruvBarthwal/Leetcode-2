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
int findtarget(vector<int>& inorder,int element){
    for(int i =0;i<inorder.size();i++){
        if(inorder[i] == element){
            return i;
        }
    }
    return -1;
}
TreeNode* solve(vector<int> &inorder, vector<int> &postorder, int &index, int inorderstart, int inorderend){
    if(index < 0 || inorderstart > inorderend){
        return NULL;
    }
    int element = postorder[index--];
    TreeNode* temp = new TreeNode(element);
    int position  = findtarget(inorder,element);
    temp->right = solve(inorder,postorder,index,position + 1, inorderend);
    temp->left = solve(inorder,postorder,index,inorderstart,position-1);

    return temp;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int i =n-1;
        TreeNode* ans = solve(inorder,postorder,i,0,n-1);
        return ans;
    }
};