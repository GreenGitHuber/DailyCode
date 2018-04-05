/*
给定一个二叉树，找出所有路径中各节点相加总和等于给定 目标值 的路径。

一个有效的路径，指的是从根节点到叶节点的路径。
*/
#include<vector>
#include<iostream>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution
{
public:
    std::vector<std::vector<int> > res;
    std::vector<int> v;
    int tem=0;
    std::vector<std::vector<int> >pathSum(TreeNode *root,int sum)//递归函数的返回值要想清楚，有时候是void，有时候又是最后的返回值
    {
        if(root==NULL)
        {
            return res;
        }

        v.push_back(root->val);
        tem = tem + root->val;
        if(sum==tem && root->left==NULL && root->right==NULL)
        {
            res.push_back(v);
            v.pop_back();
            tem-=root->val;
            return res;
            
        }
        pathSum(root->right,sum);
        pathSum(root->left,sum);
        v.pop_back();
        tem-=root->val;
        return res;//这一句第一次没有写，程序报错。如果函数的返回值改为void，那么这一句是不用写的。
        
    }    
};
int main()
{
    TreeNode *n1=new TreeNode(1);
    TreeNode *n2=new TreeNode(2);
    TreeNode *n3=new TreeNode(2);
    n1->left = n2;
    n1->right = n3;
    std::vector<std::vector<int> > res;
    Solution s;
    res = s.pathSum(n1,3);
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res[0].size();j++)
        {
            cout<<res[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}