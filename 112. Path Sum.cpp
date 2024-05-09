//112. Path Sum     https://leetcode.com/problems/path-sum/description/

//7msBeats74.78%    : DFS/pre-ord traversal since we calculate cumulative sum as we go down from root -> leaves; 


class Solution {
public:
    int t , flag = 0;
    void traverse(TreeNode *root, int sum){
        if(root==nullptr){
            return;
        }
        sum += root->val;
        if(root->left == NULL && root->right == NULL && sum == t){
            flag = 1;
            return;
        }
        traverse(root->left, sum);
        traverse(root->right, sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        t = targetSum;
        traverse(root, 0);
        return flag;
    }
};