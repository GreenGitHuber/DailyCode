//
//这个程序实现的是找出由相同字符组成的所有字符串，将其归为一类
///
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class solution
{
public:
    vector<vector<string> > groupAnagrams(vector<string> &strs)
    {
        map<string,vector<string> > anagrams;
        for(int i = 0;i<strs.size();i++)
        {
            //string tem = sort(strs[i].begin(),strs[i].end());//这段代码是有问题的
            //sort函数是堆str内部进行排序的
            //而且strs[i]这个在后面是要用的。
            string tem = strs[i];
            sort(tem.begin(),tem.end());
            if(anagrams.find(tem)==anagrams.end())//这个序列没有出现在map中
            {
                vector<string> item;
                anagrams[tem]=item;
            }
            anagrams[tem].push_back(strs[i]);
        }
        vector<vector<string> > res;
        // for(int i=0;i<anagrams.size();i++)
        // {
        //     res.push_back(anagrams[i]);
        // }

        for(map<string,vector<string> >::iterator it = anagrams.begin();it!=anagrams.end();it++)
        {
            res.push_back((*it).second);
        }
        return res;
    }
};

int main()
{
    std::vector<string> strs;
    strs.push_back("eat");
    strs.push_back("tea");
    strs.push_back("tan");
    strs.push_back("ant");
    strs.push_back("ate");
    strs.push_back("bat");
    solution s;
    vector<vector<string> > res=s.groupAnagrams(strs);
    cout<<res.size();
    for(vector<vector<string> >::iterator it = res.begin();it!=res.end();it++)
    {
        for(vector<string>::iterator sit = (*it).begin();sit!=(*it).end();sit++)
        {
            cout<<(*sit)<<' ';
        }
        cout<<endl;
    }
    system("pause");
    return 0;

}
