/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if(root==NULL)
        return 0;
    int leftheight=maxDepth(root->left);
    int rightheight=maxDepth(root->right);
    return 1+ (leftheight > rightheight ? leftheight : rightheight);
}