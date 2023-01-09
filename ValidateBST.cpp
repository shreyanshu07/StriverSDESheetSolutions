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
    vector<int> v;
    void push(TreeNode* root){
        if(root==NULL) return;
        push(root->left);
        v.push_back(root->val);
        push(root->right);
        return;
    }
    bool isValidBST(TreeNode* root) {
        // if(root==NULL or (root->left==NULL and root->right==NULL)) return true;
        // if(root->left!=NULL and root->left->val>=root->val) return false;
        // if(root->right!=NULL and root->right->val<=root->val) return false;
        // return isValidBST(root->left) and isValidBST(root->right);
        push(root);
        for(int i=1;i<(v.size());i++){
            if(v[i]<=v[i-1]) return false;
        }
        return true;
    }
};
