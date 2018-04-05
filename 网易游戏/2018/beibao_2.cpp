#include<stack>
#include<iostream>
#include<deque>
#include<vector>
#include<string>
#include <list>
#include <sstream>
#include <assert.h>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
    * @param m: An integer m denotes the size of a backpack
    * @param A: Given n items with size A[i]
    * @return: The maximum size
    */
    int res_num = 0;

    int max(int v1, int v2) {
        if (v1>v2) {
            return v1;
        }
        else {
            return v2;
        }
    }


    int backPack(int m, vector<int> A) {
        // write your code here
        int ** dp = new int *[A.size()];
        for (int i = 0; i<A.size(); i++) {
            // dp[i] = new int[m];
            dp[i] = new int[m+1];

        }

        for (int i = 0; i<A.size(); i++) {
            dp[i][0] = 0;
        }


        for (int j = 1; j<m + 1; j++) {

            if (A[0]<j) {
                dp[0][j] = A[0];
            }
            else {
                dp[0][j] = 0;
            }

            for (int i = 1; i<A.size(); i++) {
                if (A[i]>j) {
                    dp[i][j] = dp[i - 1][j];
                }
                else {
                    int res1 = dp[i - 1][j - A[i]] + A[i];
                    int res2 = dp[i - 1][j];
                    if (res1 > res2) {
                        dp[i][j] = res1;
                        res_num++;
                    }
                    else {
                        dp[i][j] = res2;
                    }
                    
                }
            }
        }
        return res_num;
    }
};

int main() {
    
    int n,w;
    cin >> n>>w;
    vector<int> vi;
    while (n > 0) {
        int v_ele;
        cin >> v_ele;
        vi.push_back(v_ele);
        n--;
    }


    Solution s;
    cout<<s.backPack(w, vi)/2;


    system("pause");
    return 0;
}