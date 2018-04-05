#include<assert.h>
#include<iostream>
using namespace std;


char* strcpy(char* strDest,const char* strSrc)
{
    // if(strSrc==NULL)
    //     return NULL;//这段代码是有问题的。没有考虑到strDest为NULL的情况
    

    // if(NULL==strDest||NULL==strSrc) //不检查指针的有效性，说明答题者不注重代码的健壮性。
    //     throw "point error";
    assert((strDest!=NULL) && (strSrc!=NULL));
    int len = strlen(strSrc);
    strDest[len]='\0';
    for(int i=0;i<len;++i)
    {
        strDest[i]=strSrc[i];
    }
    return strDest;
}
//大牛的写法
// char* strcpy(char *strDest,const char *strSrc)
// {
//     assert((strDest!=NULL)&&(strSrc!=NULL));
//     char *address=strDest;
//     while((*strDest++=*strSrc++)!='\0');
//     return strDest;
// }

int main()
{
    char s[123]={"1233232"};char*str=NULL;
    printf("%s\n",s);
    strcpy(str,s);
    printf("%s\n",str);

}