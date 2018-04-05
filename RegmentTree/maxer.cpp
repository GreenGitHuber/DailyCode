#include<iostream>
using namespace std;
#include<vector>
/*统计前面比自己小的数的个数

对于数组[1,2,7,8,5] ，返回 [0,1,2,3,2]
*/

struct Node{//线段树节点
    int begin;
    int end;
    int mid;
    int count;
    Node* left;
    Node* right;
    
    Node(int begin, int end){
        this->begin = begin;
        this->end = end;
        this->mid = (begin + end) / 2;
        this->count = 0;
        this->left = NULL;
        this->right = NULL;
    }
    
    int add(int num){ 
        ++count;
        if(begin == end){
            return 0;
        }else{
            if(left == NULL){
                left = new Node(begin, mid);
            }
            if(right == NULL){
                right = new Node(mid + 1, end);
            }
            
            // if(num <= mid){//返回线段树中比num小的值的数量
            //     return left->add(num);
            // }else{
            //     return left->count + right->add(num);
            // }
            if(num > mid){//返回线段树中比num大的值的数量
                return right->add(num);
            }else{
                return right->count + left->add(num);
            }
        }
    }
    
    ~Node(){
        delete this->left;
        delete this->right;
    }
};

class Solution {
public:
   /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is 
     *          smaller than it and return count number array
     */
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        // write your code here
        vector<int> r;
        if(A.size() == 0){
            return r;
        }
        
        int min = A[0];
        int max = A[0];
        for(int i = 0; i < A.size(); ++i){//找出最大和最小值
            if(A[i] < min){
                min = A[i];
            }
            
            if(A[i] > max){
                max = A[i];
            }
        }
        
        Node* node = new Node(min, max); //一边构建线段树一边计算答案
        for(int i = 0; i < A.size(); ++i){
            r.push_back(node->add(A[i]));
        }
        delete node;
        return r;
    }
};

int main()
{
    std::vector<int> v,res;
    // v.reserve(5);//1,2,7,8,5]
    v.push_back(3);
    v.push_back(2);
    v.push_back(7);
    v.push_back(8);
    v.push_back(1);
    Solution s;
    res=s.countOfSmallerNumberII(v);
    vector<int>::iterator it=res.begin();
    while(it!=res.end())
    {
        cout<<*it<<' ';
        ++it;
    }
    return 0;
}