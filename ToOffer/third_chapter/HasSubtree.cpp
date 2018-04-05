#include<iostream>
using namespace std;

class Node
{
    Node*left=NULL;
    Node* right = NULL;
    int val;
    Node(int v):val(v);
};
bool result=false;
bool HasSubTree(Node* proot,Node* pSub)
{
    if(pSub==NULL)
        return true;
    if(proot==NULL)
        return false;
    if(proot->val==pSub->val)
    {
        //这样写是不对的！！！！！！
        //正确的写法见下面
        result=HasSubTree(proot->left,pSub->left)&&HasSubTree(proot->right,pSub->right);
    }
    if(!result)
        result=HasSubTree(proot->left,pSub);
    if(!result)
        result=HasSubTree(proot->right,pSub);
    return result;
}


/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool DoseT1HaveT2(TreeNode *T1,TreeNode*T2)
    {
        if(T1==NULL&&T2==NULL)
            return true;

        if(T2==NULL&&T1!=NULL)
            return false;
        if(T2!=NULL&&T1==NULL)
            return false;
            
        else
        {
            if(T1->val==T2->val)
            {
                return DoseT1HaveT2(T1->left,T2->left)&&DoseT1HaveT2(T1->right,T2->right);
            }
            return false;
        }
    }

    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here
        bool result=false;
        if(T1!=NULL&&T2!=NULL){
            if(T1->val==T2->val)
            {
                result=DoseT1HaveT2(T1,T2);
            }
            if(!result)
            {
                result=isSubtree(T1->left,T2);
            }
            if(!result)
            {
                result=isSubtree(T1->right,T2);
            }
        }else if(T1!=NULL && T2==NULL) return true;
        else if(T1==NULL && T2==NULL) return true;
        else return false;
        

        return result;
    }
};


