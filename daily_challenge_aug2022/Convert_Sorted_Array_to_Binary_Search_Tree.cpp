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
    
    void rsubtree(int l,int r, TreeNode* root,vector<int> &nums,unordered_set<int> &s){
        if(l<r){
            int mid=(l+r)/2;
            if(s.find(mid)==s.end()){
                s.insert(mid);
                TreeNode* node=new TreeNode(nums[mid]);
                root->right=node;
                lsubtree(l,mid,node,nums,s);
                rsubtree(mid,r,node,nums,s);
            }
        }
        return;
    }
    
    void lsubtree(int l,int r, TreeNode* root,vector<int> &nums,unordered_set<int> &s){
        if(l<r){
            int mid=(l+r)/2;
            if(s.find(mid)==s.end()){
                s.insert(mid);
                TreeNode* node=new TreeNode(nums[mid]);
                root->left=node;
                lsubtree(l,mid,node,nums,s);
                rsubtree(mid,r,node,nums,s);
            }
        }
        return;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums){
        TreeNode* root= new TreeNode();
        unordered_set<int> s;
        int l=0;
        int r=nums.size();
        int mid=(l+r)/2;
        s.insert(mid);
        root->val=nums[mid];
        lsubtree(l,mid,root,nums,s);
        rsubtree(mid,r,root,nums,s);
        return root;
    }
};
