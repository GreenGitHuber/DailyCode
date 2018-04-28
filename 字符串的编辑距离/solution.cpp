#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

using namespace std;

int min_of_three(int a, int b, int c){
	int min1 = min(a, b);
	int min2 = min(min1, c);
	return min2;
}

int edit_distance(char *a, char *b, int i, int j)
{
	if (j == 0) {
		return i;
	}
	else if (i == 0) {
		return j;
		// 算法中 a, b 字符串下标从 1 开始，c 语言从 0 开始，所以 -1
	}
	else if (a[i - 1] == b[j - 1]) {
		return edit_distance(a, b, i - 1, j - 1);
	}
	else {
		return min_of_three(edit_distance(a, b, i - 1, j) + 1,
			edit_distance(a, b, i, j - 1) + 1,
			edit_distance(a, b, i - 1, j - 1) + 1);
	}
}



int main()
{

	char s1[] = "abcd";
	char s2[] = "abc";
	cout<<edit_distance(s1, s2, sizeof(s1), sizeof(s2));
	

	return 0;
}

