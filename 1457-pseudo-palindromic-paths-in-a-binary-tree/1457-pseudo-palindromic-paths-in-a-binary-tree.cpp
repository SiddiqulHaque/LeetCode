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
int ans=0;
void temp(TreeNode *root,vector<int>&freq){
    if(root==NULL){
        return;
    }
    freq[root->val]++;
    if(root->left==NULL and root->right==NULL){
        int cnt=0;
        for(auto it:freq){
            if(it%2!=0){
                cnt++;
            }
        }
        if(cnt<=1){
            ans++;
        }
    }
    temp(root->left,freq);
    temp(root->right,freq);
    freq[root->val]--;
    return;
}
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10,0);
        temp(root,freq);
        return ans;
    }
};