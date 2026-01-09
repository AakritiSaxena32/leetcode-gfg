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
    long maxP;
    long SUM;
public:
    long long totalSum(TreeNode* root)
    {
        if(root == NULL) return 0;
        int leftSubtreeSum = totalSum(root->left);
        int rightSubtreeSum = totalSum(root->right);
        long subtreeSum = root->val + leftSubtreeSum + rightSubtreeSum;
        long remainingSubtree = SUM - subtreeSum;
        maxP = max(maxP, subtreeSum*remainingSubtree);
        return subtreeSum;
    }
    int maxProduct(TreeNode* root) {
        if(root == NULL) return 0;
        maxP = 0;
        SUM = totalSum(root);
        totalSum(root);
        return maxP%(1000000007);
    }
};