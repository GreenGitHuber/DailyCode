#include <iostream>
#include <set>
using namespace std;
#include <string>
#include <vector>
using namespace std;

#define ALPHABET_SIZE 26

typedef struct trie_node
{
    int count;   // 记录该节点代表的单词的个数
    bool isword;
    trie_node *children[ALPHABET_SIZE]; // 各个子节点
}*trie;

trie_node* create_trie_node()
{
    trie_node* pNode = new trie_node();
    pNode->count = 0;
    pNode->isword = false;
    for(int i=0; i<ALPHABET_SIZE; ++i)
        pNode->children[i] = NULL;
    return pNode;
}

void trie_insert(trie root, char* key)
{
    trie_node* node = root;
    char* p = key;
    while(*p)
    {
        if(node->children[*p-'a'] == NULL)
        {
            node->children[*p-'a'] = create_trie_node();
        }
        node = node->children[*p-'a'];
        ++p;
    }
    node->count += 1;
    node->isword = true;
}

/**
 * 查询：不存在返回0，存在返回出现的次数
 */
int trie_search(trie root, char* key)
{
    trie_node* node = root;
    char* p = key;
    while(*p && node!=NULL)
    {
        node = node->children[*p-'a'];
        ++p;
    }

    if(node == NULL)
        return 0;
    else
        return node->count;
}
//到前缀的起点
trie_node* trie_searchroot(trie root, char* key)
{
    trie_node* node = root;
    char* p = key;
    while(*p && node!=NULL)
    {
        node = node->children[*p-'a'];
        ++p;
    }

    if(node == NULL)
        return nullptr;
    else
        return node;
}
//前序遍历输出带有前缀key的所有字符串
void pre(trie root,string &str,const string &key){
    if(root==NULL)
        return;
    for(int i =0;i<ALPHABET_SIZE;i++){
        if(root->children[i]) {
           str += (char) 'a' + i;
           if (root->children[i]->isword) {
               cout << key + str << endl;
           }
            pre(root->children[i],str,key);
            str.pop_back();
       }

    }
}

void get_all_word(trie root,string &word,const string &key,vector<string>&word_list){
    if(root==NULL)
        return;
    for(int i =0;i<ALPHABET_SIZE;i++){
        if(root->children[i]) {
            word += (char) 'a' + i;
            if (root->children[i]->isword) {
                word_list.push_back(key+word);
            }
            get_all_word(root->children[i],word,key,word_list);
            word.pop_back();
        }

    }
}
int main()
{
    // 关键字集合
    char keys[][10] = {"the", "a", "there", "answer", "any", "by", "bye", "their","then","these"};
    trie root = create_trie_node();

    // 创建trie树
    for(int i = 0; i < 10; i++)
        trie_insert(root, keys[i]);

    // 检索字符串
    char s[][32] = {"Present in trie", "Not present in trie"};
    printf("%s --- %s\n", "the", trie_search(root, "the")>0?s[0]:s[1]);
    printf("%s --- %s\n", "these", trie_search(root, "these")>0?s[0]:s[1]);
    printf("%s --- %s\n", "their", trie_search(root, "their")>0?s[0]:s[1]);
    printf("%s --- %s\n", "thaw", trie_search(root, "thaw")>0?s[0]:s[1]);

    trie_node*  p = trie_searchroot(root,"th");
    string str="";
    string key ="th";
    vector<string> word_list;
    get_all_word(p,str,key,word_list);
    for(auto it = word_list.begin();it!=word_list.end();it++){
        cout<<*it<<endl;
    }
    cout<<"*******************"<<endl;
    pre(p,str,key);


    return 0;
}
