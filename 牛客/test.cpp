// #include <string.h>
#include<string>
#include <stdio.h>
#include<iostream>
using namespace std;
int main()

{
// char s[80], c='a';
    char c = 'a';
int i = 0;
// scanf("%s", s);
string s;
cin>>s;
while(s[i] != '\0')
{
if (s[i] == c)
s[i] -= 32;
else if (s[i] == c - 32)
s[i] += 32;
i++;
}
cout<<s;
// puts(s);
}
