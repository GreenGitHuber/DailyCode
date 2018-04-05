#include<assert.h>
#include<iostream>
using namespace std;

char* strcat(char* des,const char* src)
{
    assert((des!=NULL) &&(src!=NULL));
    char * add = des;
    while(*des!='\0')
        ++des;
    while(*src!='\0')
        *des++=*src++;
    *des ='\0';
    return add;
}
int main()
{
    char s[8]={"1233232"};char str[123]={"1234"};
    printf("%s\n",s);
    printf("%s\n",str);
    char * ans=strcat(str,s);
    printf("%s\n",ans);
}
// #include <assert.h>
// #include <stdio.h>

// char* strcat(char* des, const char* src)   // const表明为输入参数 
// {  
//     assert((des!=NULL) && (src!=NULL));
//     char* address = des;
//     while(*des != '\0')  // 移动到字符串末尾
//         ++des;
//     // while(*des++ = *src++)
//     while((*des++ = *src++) != '\0')  
//         ;
//     return address;
// }
// int main()
// {
//     char s[8]={"1233232"};char str[123]={"1234"};
//     printf("%s\n",s);
//     printf("%s\n",str);
//     char * ans=strcat(str,s);
//     printf("%s\n",ans);
// }
