#include<iostream>
using namespace std;
#include<string>

int main()
{
    FILE *fp;
    char buffer[100] ="This is test file";
    if((fp = fopen("./example.txt","w"))==0)
    {
        cout<<"open fail"<<endl;
        exit(1);
    }

    fwrite(buffer,1,strlen("This is test file")+1,fp);

    fclose(fp);
    return 0;

}