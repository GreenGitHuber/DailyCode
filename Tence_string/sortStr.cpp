//小Q最近遇到了一个难题：把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，且不能申请额外的空间。
/*你能帮帮小Q吗？
AkleBiCeilD->kleieilABCD
*/
/*这道题关键在于相对位置不变这个点，冒泡排序相对位置不变*/
#include<iostream>
using namespace std;
#include<string>
int main()
{
    string str;
    cin>>str;
    int len = str.length();
    int l=0;
    if(len<=0 )  
        cout<<"";
    for(int i=len-1;i>=0;i--)
    {
        if(str[i]>='A'&&str[i]<='Z')
        {
            char t = str[i];
            for(int j=i;j<len-1-l;j++)
            {
                str[j]=str[j+1];
            }
            str[len-1-l]=t;
            l++;
        }
    }
    for(int i=0;i<len;i++)
    {
        cout<<str[i];
    }
    return 0;  
}