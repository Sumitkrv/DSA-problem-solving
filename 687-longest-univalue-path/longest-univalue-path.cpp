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
    int height(TreeNode* node, int &longest){
        if(node==NULL) return 0;
        int left=height(node->left, longest);
        int right=height(node->right, longest);
        if(node->left && node->left->val==node->val){
            left++;
        }
        else{
            left=0;
        }
        if(node->right && node->right->val==node->val){
            right++;
        }
        else{
            right=0;
        }
        longest=max(longest, left+right);
        return max(left, right);
    }
    int longestUnivaluePath(TreeNode* root) {
        int longest=0;
        height(root, longest);
        return longest;
    }
};