#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    char data[100];
    // 以写的模式打开文件
    ofstream ofile;
    ofile.open("test.txt");
    cout<<"write to the file"<<endl;
    cout<<"Enter your name";
    cin.getline(data,100);
    //向文件写入用户输入的数据
    ofile<<data<<endl;

    cout<<"Enter your age:";
    cin>>data;
    ofile<<data<<endl;

    //关闭打开的文件
    ofile.close();
    //以读的形式打开文件
    ifstream ifile;
    ifile.open("test.txt");
    cout<<"Reading from the file"<<endl;
    ifile>>data;

    //在屏幕上输出数据
    cout<<data<<endl;
    // 再次从文件读取数据，并显示它
    ifile >> data; 
    cout << data << endl; 
    // 关闭打开的文件
   ifile.close();
 
   return 0;
   

}