#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    /**
     * @param str: A string
     * @return: An integer
     */
    enum Statue{value=0,invalue};//statue
    //bool negative;
    int g_nstatue;//做为全局标志变量；
    int atoi(string &str) {
        // write your code here
        g_nstatue=invalue;
        long long num = 0;
        char * cstr=(char*)str.c_str();
        while(*cstr==' ')//考虑"    -5211314"这样的情况
            cstr++;
        if(cstr!=NULL&& *cstr!='\0')
        {
            bool negative=false;//标志是否为负数
            if(*cstr =='-')
            {
                negative=true;
                cstr++;//指针往下移一位
            }
            else if(*cstr =='+')
                cstr++;
            if(*cstr!='\0')
            num=strtointcore(cstr,negative);
        }  
        return num;    
    }
    int strtointcore(char*str,bool negative)
    {
        long long num = 0;//可以这样吗？
        while(*str!='\0')
        {
            if(*str>='0'&&*str<='9')
            {
                if(negative)
                {
                    num=num*10-((*str)-'0');
                   
                }
                else
                    num=num*10+((*str)-'0');
                if(!negative&&num>0x7FFFFFF)
                {
                    num=INT_MAX;
                    break;
                }
                if(negative&&num<(signed int)0x80000000)
                {
                    
                    num = INT_MIN;
                    break;
                }
                str++;
            }
            else if(*str =='.')
            {
                if(!negative&&num>0x7FFFFFF)
                {
                    num=INT_MAX;
                }
                if(negative&&num<(signed int)0x80000000)
                {
                    
                    num = INT_MIN;
                }
                break; 
            }
            else 
            {
                if(!negative&&num>0x7FFFFFF)
                {
                    num=INT_MAX;
                }
                if(negative&&num<(signed int)0x80000000)
                {
                    num = INT_MIN;
                }
                //num=0;
                break;
            }
            
        }
        if(*str=='\0')
            g_nstatue=value;
        return num;

    }

};

int main()
{
    Solution s;
    string str = "-2147483649";
    int i = s.atoi(str);
    cout<<i<<endl;

}