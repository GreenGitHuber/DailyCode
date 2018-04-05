#include<iostream>
using namespace std;

void printNumber(char *number)
{
    bool p=false;
    int length=strlen(number);
    for(int i=0;i<length;++i)
    {
        if(!p && number[i]!='0')
        {
            p=true;
        }
        if(p)
            cout<<number[i];
    }
    cout<<endl;
}

void Print1ToMaxOfDigitsRecursively(char* number,int length,int index)
{
    if(index==length)
    {
        printNumber(number);
        return;
    }
    for(int i=0;i<10;++i)
    {
        number[index]=i+'0';

        Print1ToMaxOfDigitsRecursively(number,length,index+1);
    }

}
void Print1ToMaxOfDigits(int n)
{
    if(n <= 0)
        return;
    char *number = new char[n+1];
    number[n]='\0';
    // for(int i=0;i<10;++i)
    // {
    //     number[0]=i+'0';
    //     Print1ToMaxOfDigitsRecursively(number,n,0);
    // }
    Print1ToMaxOfDigitsRecursively(number,n,0);
    delete[]number;
}

int main()
{
    int n;
    cin>>n;
    Print1ToMaxOfDigits(n);
    return 0;
}