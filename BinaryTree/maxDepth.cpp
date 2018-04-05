#include<iostream>
#include<queue>
using namespace std;

class TreeNode {
 public:
      int val;
      TreeNode *left, *right;
      TreeNode(int val) {
          this->val = val;
          this->left = this->right = NULL;
      }
};
 

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int dep=0;
int max=0;
void dfs(TreeNode * root)
{
    if(root==NULL)
    {
        return;
    }
    dep++;
    dfs(root->left);
    dfs(root->right);
    if(dep>max)
        max=dep;
    dep--;
}
    int maxDepth(TreeNode * root) {
        // write your code here
     int res=dfs(root);
     return res;

        
    }
};