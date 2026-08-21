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
    int maxSum(TreeNode* root, int &sum){
        if(root==NULL) return 0;
        int leftSum=maxSum(root->left, sum);
        int rightSum=maxSum(root->right, sum);
        sum=max(sum, max(0,leftSum)+max(0,rightSum)+ root->val);
        return max(0, max(leftSum, rightSum))+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        maxSum(root, sum);
        return sum;
        
    }
};