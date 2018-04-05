///
//这个程序实现的是最长回文串
//题目的意思是：给定字符串s，利用字符串s里的字符可以实现构成的最长回文串
///
#include<iostream>
#include<string>
using namespace std;

class solution
{
public:
    int longestPalindrome(string s)
    {
        //字符hash
        int char_map[128]={0};
        int max_length =0;//最长回文串的长度
        int flag=0;//是否有中心点
        for(int i =0;i<s.length();i++)
        {
            char_map[s[i]]++;
        }
        for(int i =0;i<128;i++)
        {
            if(char_map[i] % 2)//奇数
            {
                max_length +=char_map[i]-1;
                flag =1;
            }
            else
            {
                max_length +=char_map[i];
            }
        }
        return max_length+flag;

    }
};

int main()
{
    string str="aabbsssddd";
    solution s;
    cout<<s.longestPalindrome(str);
    system("pause");
    return 0;

}