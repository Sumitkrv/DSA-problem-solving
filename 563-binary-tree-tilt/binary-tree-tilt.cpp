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
    int height(TreeNode* node, int &sum){
        if(node==NULL) return 0;
        int lh=height(node->left, sum);
        int rh=height(node->right, sum);
        int tilt=abs(lh-rh);
        sum+=tilt;
        return node->val +lh+rh;
    }
    int findTilt(TreeNode* root) {
        int sum=0;
        height(root, sum);
        return sum;
    }
};