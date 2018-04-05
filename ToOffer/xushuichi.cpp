/*蓄水池问题：
如何随机从n个对象中选择一个对象，这n个对象是按序排列的，
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// generate a random number between i and k,
// both i and k are inclusive.
int randint(int i, int k)
{
    if (i > k)
    {
        int t = i; i = k; k = t; // swap
    }
    int ret = i + rand() % (k - i + 1);
    return ret;
}

// take m samples to result from input of n items.
bool reservoir_sampling(const int *input, int n, int *result, int m)
{
    srand(time(NULL));
    if (n < m || input == NULL || result == NULL)
        return false;
    for (int i = 0; i != m; ++i)
        result[i] = input[i];

    for (int i = m; i != n; ++i)
    {
        int j = randint(0, i);//这一步的意思就是以k/m的概率选中这个元素
        cout<<j<<endl;
        if (j < m)
            result[j] = input[i];   
    }
    return true;
}

int main()
{
    const int n = 100;
    const int m = 10;
    int input[n];
    int result[m];

    for (int i = 0; i != n; ++i)
        input[i] = i;
    if (reservoir_sampling(input, n, result, m))
        for (int i = 0; i != m; ++i)
            cout << result[i] << " ";
    cout << endl;
    return 0;
}