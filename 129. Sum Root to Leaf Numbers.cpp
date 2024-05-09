//129. Sum Root to Leaf Numbers     https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

//0msBeats100.00%of users with C++


class Solution {
public:
    long ans = 0;

    void inorder(TreeNode *root, long sum){
        if(root==NULL){
            return;
        }
        sum += root->val;
        if(root->left==NULL && root->right==NULL){
            ans+=sum;
        }
        inorder(root->left, sum*10);
        inorder(root->right, sum*10);
    }
    int sumNumbers(TreeNode* root) {
        inorder(root, 0);
        return ans;
    }
};