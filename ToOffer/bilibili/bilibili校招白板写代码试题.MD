# 校招算法题

## 1. 斐波纳契数列

#### 问题 ：查找斐波纳契数列中第 N 个数 


#### 描述 ：所谓的斐波纳契数列是指，

1. 前2个数是 0 和 1
2. 第 i 个数是第 i-1 个数和第i-2 个数的和

斐波纳契数列的前10个数字是：0, 1, 1, 2, 3, 5, 8, 13, 21, 34 

#### 样例：

给定 1，返回 0

给定 2，返回 1

给定 10，返回 34

#### 挑战:

使用非递归或尾递归的方法实现

```
//递归版本
int fibonacci(int n) {
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    return fibonacci(n-1)+fibonacci(n-2);
}
```

```
//非递归版本
int fibonacci(int n) {
    int result[100];  //假设n小于100
    result[1]=0;
    result[2]=1;
    for(int i=3;i<=n;i++){
        result[i]=result[i-1]+result[i-2];
    }
    return result[n];	
}
```

```
// 尾递归版本
int fib(int a,int b,int n) {
    if(n==1){
        return a;
    }
    fib(b,a+b,n-1);
}

int fibonacci(int n) {
    return fib(0,1,n);
}
```

## 2. 反转链表

#### 问题：反转一个链表

#### 描述：给出一个链表1->2->3->null，这个翻转后的链表为3->2->1->null

#### 挑战：

时间复杂度为O(n) , 空间复杂度为O(1)


```
//思路：从原链表的头部一个一个取节点并插入到新链表的头部

/**
 * Definition of ListNode
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 * }
 */

//将node节点插入到newhead节点的后面
void  insert(ListNode * newhead,ListNode * node){
    ListNode * q = newhead->next;
    newhead->next=node;
    node->next=q;
}
ListNode *reverse(ListNode *head) {
    // write your code here
    
    //考虑链表为空的情况
    if(head==NULL){
        return NULL;
    }
    //考虑链表只有一个节点的情况
    if(head->next==NULL){
        return head;
    }

    ListNode * newhead=new ListNode();
    newhead->next=head;
    ListNode * p=head->next;
    head->next=NULL;

    //从原链表的头部一个一个取节点并插入到新链表的头部
    while(p!=NULL){
        ListNode * node =p;
        p=p->next;
        insert(newhead,node);
    }
    return newhead->next;
}
```

## 3. 数字字符串转换为数字

#### 问题：将一个数字类型的字符串转换为数字

#### 描述：对于一个字符串 "123", 将它转换为123 (这个123是int类型，不是字符串)

#### 挑战：

1. 不使用编程语言的库函数
2. 考虑数字的正负号，比如输入 +123，输出123；输入-123，输出-123
3. 考虑异常，如果输入的字符串里面有非数字的字符怎么办，比如 +123a456

```
int str_2_int(char *p){  
    int len =  strlen(p);  
    if(len<=0){return;}  
    int sym = 1; //'+'为1  
    int pos =0;  
    if(p[0]=='+'){  
        pos ++;  
        sym = 1;  
    }  
    else if(p[0]=='-'){  
        pos ++;  
        sym = -1;  
    }  
    int sum = 0;  
    int i = 0;  
    for(i=pos;i<len;i++)  {
        if(p[i]>'9'&&p[i]<'0'){return;}   /*其他字符*/  
        sum = sum*10+p[i]-'0';
        if(sum<0){return;}      /*溢出*/   
    }  
    if(p[0]=='-'){  
        sum = sum*sym;  
    }
    return sum;
}  
```

## 4. 第K大的数字

#### 问题：第K大的数字

#### 描述：在一个乱序的数组里面找到第k大的数字

#### 样例：

给出数组[9,3,2,4,8], k=3, 返回 4;

给出数组[5,1,3,2,6], k=2, 返回 5;

#### 挑战：

在不排序的情况下面找到答案

```
//思路1
/*
    step1：使用任何的排序算法完成排序
    step2：然后访问下标k，找到第k大的元素
*/
```

```
//思路2
/*
思路：利用快速排序的思想来实现

假设N个数存储在数组S中，从数组中随机找一个元素X，将数组分成两部分Sa和Sb.Sa中的元素大于等于X,Sb中的元素小于X。
出现如下两种情况：
(1)若Sa组的个数大于或等于K，则继续在sa分组中找取最大的K个数字 。
(2)若Sa组中的数字小于K ，其个数为T，则继续在sb中找取 K-T个数字 。
一直这样递归下去，不断把问题分解成小问题，平均时间复杂度为O(N*logK)。
*/


//实现
/*将数组a[s]...a[t]中的元素用一个元素划开，保存中a[k]中*/
void partition(int a[], int s,int t,int &k)  
{  
    int i,j,x;  
    x=a[s];    //取划分元素   
    i=s;        //扫描指针初值   
    j=t;  
    do  
    {  
        while((a[j]<x)&&i<j) j--;      //从右向左扫描,如果是比划分元素小，则不动
        if(i<j) a[i++]=a[j];           //大元素向左边移   
        while((a[i]>=x)&&i<j) i++;     //从左向右扫描，如果是比划分元素大，则不动
        if(i<j) a[j--]=a[i];           //小元素向右边移   
    }while(i<j); //直到指针i与j相等    
    a[i]=x;      //划分元素就位   
    k=i;  
}  
/*查找数组前K个最大的元素，index:返回数组中最大元素中第K个元素的下标(从0开始编号),high为数组最大下标*/
int FindKMax(int a[],int low,int high,int k)
{ 
    int q;
    int index=-1;
    if(low < high)  
    {  
        partition(a , low , high,q);  
        int len = q - low + 1; //表示第几个位置    
        if(len == k)  
            index=q; //返回第k个位置   
        else if(len < k)   
            index= FindKMax(a , q + 1 , high , k-len);     
        else 
            index=FindKMax(a , low , q - 1, k);  
    }  
    return index;
}
int main()
{
    int a[]={20,100,4,2,87,9,8,5,46,26};  
    int Len=sizeof(a)/sizeof(int); 
    int K=4;
    FindKMax(a , 0 , Len- 1 , K) ;    
    for(int i = 0 ; i < K ; i++)  
        cout<<a[i]<<" ";  
    return 0;
}
*/
```

## 5. 链表倒数第K个节点

#### 描述：对于给出的一个链表，返回链表中倒数第k个节点

#### 样例：给出链表 3->2->1->5->null和n = 2，返回倒数第二个节点的值1.

```
/*
思路：采用双指针，一个指针先从链表头开始步进n步，然后另一个指针从头开始，两个指针一同步进直到达到链表尾。这是第二个指针所指的节点即为链表的倒是第n个节点。
*/

ListNode* KthToLast(ListNode *head, int n) {
    ListNode *p=head;
    ListNode *q=head;
    for(int i=0;i<n;i++){
        p=p->next;
    }
    while(p!=NULL){
        p=p->next;
        q=q->next;
    }
    return q;
}
```

## 6. 字符串空格替换

#### 描述:

设计一种方法，将一个字符串中的所有空格替换成 %20 
（假设该字符串有足够的空间来加入新的字符）

#### 样例：

对于字符串"Mr John Smith",长度为 13，替换空格之后变为"Mr%20John%20Smith"，长度是17。

```
/* 
思路：
1. 先遍历一次字符串，统计空格的个数，计算出新的字符串的长度
2. 在遍历一次字符串，替换空格字符
*/

int replaceBlank(char string[], int length) {
    //统计空格的个数
    int BlankNums=0;
    for(int i=0;i<length;i++){
        if(string[i]==' '){
            BlankNums++;
        }
    }
    //新的字符串的长度
    int Strlen=length+BlankNums*2;
    
    //新的字符串比原来增加的长度
    int diff=BlankNums*2;
    
    //重新遍历字符串，并且将空格字符替换为%20
    for(int i=length-1;i>=0;i--){
        if(string[i]!=' '){
            string[i+diff]=string[i];
        }
        else{
            string[i+diff]='0';
            diff--;
            string[i+diff]='2';
            diff--;
            string[i+diff]='%';		
        }
    }
    return Strlen;
}
```

## 7. 判断二进制中有多少个1

#### 描述：

计算在一个 32 位的整数的二进制表示中有多少个1

#### 样例：

给定 32 (100000)，返回 1

给定 5 (101)，返回 2

给定 1023 (111111111)，返回 9

#### 挑战：
如果是负数怎么办?

```
int countOnes(int num) {
    int count = 0;
    //负数的情况
    if (num < 0) {
        count++;
        num = num ^ 0x80000000;
    }
    while (num > 0) {
        if (num & 1) {
            count++;
        }
        num = num >> 1;
    }
    return count;
}
```

## 8. 合并排序数组

#### 问题：合并两个排序的整数数组A和B变成一个新的数组

#### 描述：

假设有两个排序的数组A和B，把数组A和数组B按照顺序合并起来，合并的数放在数组A里面（假设数组A 足够长）

#### 样例：

给出 A = [1, 3, 5], B = [2, 4]，合并之后 A 将变成 [1,2,3,4,5]

```
void mergeSortedArray(int A[], int m, int B[], int n) {
    // write your code here
    int pos = m + n - 1;
    int posA = m - 1;
    int posB = n - 1;
    while (posA >= 0 && posB >= 0) {
        if (A[posA] > B[posB]) {
            A[pos--] = A[posA--];
        } else {
            A[pos--] = B[posB--];
        }
    }
    while (posA >= 0) {
        A[pos--] = A[posA--];
    }
    while (posB >= 0) {
        A[pos--] = B[posB--];
    }
}
```

## 9. 两数之和

#### 描述：

给出一个整数数组，找到两个数使他们的和等于一个给定的数,然后返回这两个数对应的下标。

#### 样例：

给出 numbers = [11, 7, 2, 15], target = 9, 因为2+7=9，所以返回他们对应的下标[1,2]

#### 挑战：

时间复杂度小于 O(n^2)

```
//思路1:暴力法 O(n^2)，使用两个循环,遍历所有元素
bool IsExistSumOfTwoNum(int nArray[],int nCount,int nSum){
    bool bRet = false;
    for (int i = 0; i < nCount - 1; ++i ){
        for ( int j = i + 1; j < nCount; ++j ){
            if ( ( nArray[i] + nArray[j] ) == nSum ){
                bRet = true;
                break;
            }
        }
    }
    return bRet;	
}
```



```
/*思路2：
先对数组进行从小到大的排序，然后设置首尾指针，从首尾两端开始移动，一次移动一端的指针，直至两指针相遇或者两指针指向的数的和为指定的值
时间复杂度O(nlogn)
*/
bool IsExistSumOfTwoNum( int nArray[], int nCount, int nSum ){
	//从小到大排序
	std::sort( nArray, nArray+nCount, std::less<int>() );
	//首尾指示
	int i = 0; 
	int j = nCount - 1;
	bool bRet = false;
	while( i < j ){
		if ( ( nArray[i] + nArray[j] ) == nSum ){
			bRet = true;
			break;
		}
		else if ( ( nArray[i] + nArray[j] ) > nSum  ){
			--j;
		}
		else{
			++i;
		}
	}
	return bRet;	
}
```

## 10. 奇偶分割数组

#### 问题描述 ：

对于给定的一个数组，调整这个数组，使得奇数在前偶数在后

#### 样例：

给定 [1, 2, 3, 4]，返回 [1, 3, 2, 4]

#### 挑战 ：
在原数组中完成，不使用额外空间


```
/*
思路：用两个指针i和j,分别从数组的首部和尾部往中间扫描，如果发现有偶数出现在奇数前面的情况，就交换他们的位置，直到扫描完整个数组
*/
void partitionArray(int[] nums) {
    int i=0;
    int j=nums.length - 1;
    while(i<j){
        while(nums[i]%2==1){
            i++;
        }
        while(nums[j]%2==0){
            j--;
        }
        if(i<j){
            //交换num[i] 和num[j]
            nums[i]=nums[i]+nums[j];
            nums[j]=nums[i]-nums[j];
            nums[i]=nums[i]-nums[j];
        }
    }
}
```
