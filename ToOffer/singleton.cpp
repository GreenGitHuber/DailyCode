#include<iostream>
using namespace std;
class singleton
{
private:
    singleton();
    static singleton* instance;
public:
    static singleton* Instance()
    {
        
            if(instance==NULL)
                instance = new singleton();
            return instance;
        
    }
    
};

int main()
{
    singleton *s1= singleton ::Instance();
    return 0;
}