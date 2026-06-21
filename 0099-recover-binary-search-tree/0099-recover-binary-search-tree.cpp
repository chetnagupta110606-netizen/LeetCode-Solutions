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
    TreeNode *first=NULL,*sec=NULL,*prev= NULL;
    void recoverTree(TreeNode* root){
        while(root != NULL){
            if(root->left == NULL){
            if(prev != NULL && prev->val> root->val){
                if(!first){
                    first=prev;
                }
                sec=root;
            }
            prev=root;
            root=root->right;
        }
        else{
            //find IP
            TreeNode *IP=root->left;
            while(IP->right != NULL && IP->right != root){
                IP=IP->right;
            }
            if(IP->right == NULL){
                IP->right=root;
                root=root->left;
            }
            else{
                if(prev != NULL && prev->val > root->val){
                    if(!first){
                        first=prev;
                    }
                    sec=root;
                }
                prev=root;
                IP->right=NULL;
                root=root->right;
            }
        }
        }

        int temp=first->val;
        first->val=sec->val;
        sec->val=temp;
    }
};