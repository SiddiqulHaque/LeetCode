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
    int findBottomLeftValue(TreeNode* root) {
        if(root->left==NULL and root->right==NULL){
            return root->val;
        }
        queue<TreeNode*> q;
        int count=0;
        vector<vector<int>> ans;
        TreeNode* temp;
        q.push(root);
        vector<int> v;
        v.push_back(root->val);
        ans.push_back(v);
        while(!q.empty()){
            count=q.size();
            v.clear();
            for(int i=0;i<count;i++){
                temp=q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                    v.push_back(temp->left->val);
                }
                if(temp->right){
                    q.push(temp->right);
                    v.push_back(temp->right->val);
                }
            }
            if(v.size()!=0){
            ans.push_back(v);
            }
        }
        int sz=ans.size();
        return ans[sz-1][0];
    }
};