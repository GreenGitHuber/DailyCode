#include<iostream>
using namespace std;
#include<string>

int main()
{
    FILE * fp;
    int len;
    char buffer[100];
    if((fp = fopen("./example.txt","w"))==0)
    {
        cout<<"open error"<<endl;
        exit(1);
    }
    fread(buffer,1,2 ,fp);
    printf("%s\n", buffer);
    fread(buffer,1,2 ,fp);
    printf("%s\n", buffer);
    fclose(fp);
    return 0;
}