//114. Flatten Binary Tree to Linked List      https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

//3msBeats82.47%
class Solution {
public:
    vector<int> predata;
    void preorder(TreeNode *root){
        if(root!=NULL){
            predata.push_back(root->val);
        
        preorder(root->left);
        preorder(root->right);
        }
    }
    void flatten(TreeNode* root) {
        preorder(root);
        TreeNode *temp = root;
        for(int i=1; i<predata.size(); i++){
            temp->right = new TreeNode(predata[i]);
            temp->left = NULL;
            temp = temp->right;
        }
        
    }
};

//!  7msBeats29.86%
//Recursively flatten L.SubTree & R.SubTree

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==nullptr)return;

        TreeNode *temp = root->left;
        TreeNode *temp1 = root->right;

        root->left = NULL;

        flatten(temp);
        flatten(temp1);

        root->right = temp;
        TreeNode *curr = root;
        while(curr->right!=NULL){curr=curr->right;}
        curr->right = temp1;
        
    }
};