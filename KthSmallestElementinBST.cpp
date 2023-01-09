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
    int fun(vector<int> v,int k){
        sort(v.begin(),v.end());
        return v[k-1];
    }
    void add(TreeNode* root){
        if(root==NULL) return;
        v.push_back(root->val);
        add(root->right);
        add(root->left);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        add(root);
        return fun(v,k);
    }
};
