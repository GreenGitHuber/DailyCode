#include<iostream>
using namespace std;

class m_string
{
public:
    m_string(char* str=NULL);
    m_string(m_string &other);
    m_string& operator = (const m_string &other);
    ~ m_string();
private:
    char * m_data;
};

m_string:: m_string(char* str)
{//普通构造函数
    if(str==NULL)
        {
            m_data = new char[1];
            *m_data='\0';
        }
    else
    {
        int len = strlen(str);
        m_data = new char[len+1];
        strcpy(m_data,str);
    }
    cout<<"construct func"<<endl;
}

m_string::m_string(m_string &other)
{//拷贝构造函数
    int len = strlen(other.m_data);
    m_data = new char[len+1];
    strcpy(m_data,other.m_data);
    cout<<"copy construct func"<<endl;

}
m_string& m_string::operator = (const m_string& other)
{
    // if(other==this)//这里又错了,因为this是一个m_string *指针类型，所以other需要取址
    if(this == &other)
    {
       // return this;//这是错误的
       return *this;
   }
   // delete this.m_data;// 这里也是不对的。
   delete []m_data;//释放数组应该用delete[]
   m_data=NULL;
   int len = strlen(other.m_data);
    m_data = new char[len+1];
    strcpy(m_data,other.m_data);
   return *this;
    cout<<"fuzhi construct func"<<endl;

}

m_string::~m_string()
{
    delete[] m_data;
    m_data=NULL;
    cout<<"destruct func"<<endl;

}

int main()
{
    m_string s1("hello");
    m_string s2=s1;
    m_string s3;
    s3=s1;

     system("pause");
     return 0;

}