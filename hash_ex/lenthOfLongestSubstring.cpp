///
//这个程序实现的是最长无重复字串，注意是字串，不是子序列。两者的区别在于字串必须是连续的
////
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class solution
{
public:
    int lengthOfLongestSubstring(string &s)
    {
        int begin=0;
        int i =0;
        int char_map[128]={0};
        int result=0;
        string word="";
        while(i<s.length()&&begin<s.length())
        {
            if(!char_map[s[i]])
            {
                //没有重复的字符
                char_map[s[i]]=1;
                word+=s[i];
                if(word.length()>result)
                    result=word.length();
                i++;
            }
            else//出现了重复的字符，那么就要移动begin，直到跳过那个重复的字符。
            {
                while(char_map[s[i]])
                {
                    char_map[s[begin]]--;
                    begin++;  
                }
                word="";
                for(int j = begin;j<i;j++)
                    word+=s[j];
            }
        }
        return result;
    }
};
int main()
{
    string str="abcacbaa";
    solution s;
    int res = s.lengthOfLongestSubstring(str);
    cout<<res<<endl;
    return 0;
}









