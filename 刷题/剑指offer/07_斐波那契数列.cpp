
#include <iostream>

using namespace std;

class Solution {
public:
	int Fibonacci(int n)
	{
		if (n < 2)
		{
			return n;
		}
		int pre1 = 0;
		int pre2 = 1;
		int fi = 1;
		for (int i = 2; i < n; ++i)
		{
			pre1 = pre2;
			pre2 = fi;
			fi = pre1 + pre2;
		}
		return fi;
	}
};

// 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。 
// n<=39 


int main()
{
	Solution a;
	auto ret = a.Fibonacci(5);
	return 0;
}


