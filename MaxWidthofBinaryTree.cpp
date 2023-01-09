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
#define ull unsigned long long
#define um unordered_map
class Solution {
    
public:
    int widthOfBinaryTree(TreeNode* root) {
        um<int,ull> f;
        return dfs(root,0,0,f); 
    }
    private:
    ull dfs(TreeNode* root, int l, ull i, um<int,ull>&m) {
        if(!root) return 0;
        if(m.find(l)==m.end()) m[l] = i;
        ull left = dfs(root->left,l+1,2*i,m); 
        ull right = dfs(root->right,l+1,2*i+1,m);
        return max(i-m[l]+1,max(left,right)); 
    }
};
