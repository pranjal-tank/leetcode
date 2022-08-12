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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=root;
        TreeNode* it1=root;
        TreeNode* it2=root;
        
        while(it1!=p && it2!=q){
            if(it1->val > p->val)
                it1=it1->left;
            else
                it1=it1->right;
            
            if(it2->val > q->val)
                it2=it2->left;
            else
                it2=it2->right;
            
            if(it1==it2)
                ans=it1;
            
        }
        return ans;
    }
};
