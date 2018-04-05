#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


class player
{
public:
    int hp, ap;
    int b,d;

    player(int hp,int ap,int b,int d)
    {
        this->hp=hp;  
        this->ap=ap;
        this->d=d;  
        this->b=b;  
    }

    void gongji(player &other)
    {  
        other.hp -= ap;
    }

    void huixue(int hp)
    {
        this->hp = hp;
    }

    void xiulian(int n)
    {
        hp += b *n;
    }
    void xueruo(player& other,int n)
    {
        other.ap -= d*n;
    }
    bool live()
    {
        if(hp<=0)
        {
            return false;
        }
        return true;
    }
};



int main()
{
    int hp,ap,hm,am,b,d;
    cin>>hp>>ap>>hm>>am>>b>>d;
    player *p1 = new player(hp,ap,b,d);
    player *p2 = new player(hm,am,0,0);
    int count =1;
    while(true)
    {
        if(p1->ap>p2->hp)
            break;
        if(p1->hp<=p2->ap)
        {
            if(d==0&&b==0)
                p1->huixue(hp);
            else
            {
                if(p1->ap <p2->ap && b>d)
                {
                    p1->xiulian(count);
                }
                else
                    p1->xueruo(*p2,count);
            }
        }
        else
        {
            p1->gongji(*p2);
            if(!p2->live())
            {
                break;
            }
        }
        
        p2->gongji(*p1);
        if(!p1->live())
        {
            break;
        }
        count++;
    }
    if(p1->live())
        cout<<count;
    else
        cout<<"IMPOSSIBLE"<<endl;
    return 0;

}