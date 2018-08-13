#include <iostream>
#include<string>
#include <vector>
using namespace std;
class Solution {
public:
    void splitstr(vector<string > &res,string str,string c){
        //参数c 表示以这个为划分点
        //str是待划分的string
        int pos = str.find(c);
        if(pos==string::npos) {
            res.push_back(str);
            return;
        }
        res.push_back(str.substr(0,pos));
        splitstr(res,str.substr(pos+1),c);
    }
};


int main() {
    Solution s;
    string str="student.,a,am,I";
    vector<string> strRes;
    s.splitstr(strRes,str,",");
    for(auto it=strRes.begin();it!=strRes.end();it++){
        cout<< *it<<endl;
    }
    return 0;
}
