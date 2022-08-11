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

    void inorder(TreeNode* node,vector<int> &ans){
        if(node==NULL){
           return;
        }
        inorder(node->left,ans);
        ans.push_back(node->val);
        inorder(node->right,ans);
        return;
    }
    bool isValidBST(TreeNode* root){
        vector<int> ans;
        inorder(root,ans);
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]==ans[i+1]){
                return false;
            }
        }
        if(is_sorted(ans.begin(),ans.end())){
            return true;
        }
        else{
            return false;
        }
    }
};
