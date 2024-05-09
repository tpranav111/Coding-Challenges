//104. Maximum Depth of Binary Tree     https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

//4msBeats81.91%of users with C++

class Solution {
public:
    int max = 0;
    void inorder(TreeNode *root, int ht){

        if(root!=NULL){
            inorder(root->left, ht+1);
            if(ht>max){max = ht;}
            inorder(root->right, ht+1);
        }
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL){return 0;}
        inorder(root, 0);
        return max+1;
    }
};