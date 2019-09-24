// 数组中重复的数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include <iostream>
#include <vector>

using namespace std;
class Solution 
{
public:
#if 0//自己的解法，采用哈希方式
	bool duplicate(int numbers[], int length, int* duplication)
	{
		vector<int> count(length, 0);
		for (int i = 0; i < length; ++i)
		{
			if (numbers[i] >= length)
			{
				return false;
			}
			if (count.at(numbers[i]) == 0)
			{
				count.at(numbers[i])++;
			}
			else if (count.at(numbers[i]) == 1)
			{
				*duplication = numbers[i];
				return true;
			}
		}
		return false;
	}
#else
	bool duplicate(int numbers[], int length, int* duplication)
	{
		if (numbers == NULL || length <= 0)
		{
			return false;
		}
		for (int i = 0; i < length; ++i)
		{
			if (numbers[i] < 0 || numbers[i] >= length)
			{
				return false;
			}
		}

		for (int i = 0; i < length; ++i)
		{
			while (numbers[i] != i)
			{
				int num = numbers[i];
				if (numbers[num] == num)
				{	
					*duplication = numbers[i];
					return true;
				}
				else
				{
					std::swap(numbers[num], numbers[i]);
				}
			}
		}
	}
#endif
};


// 在一个长度为n的数组里的所有数字都在0到n - 1的范围内。 
// 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。
// 请找出数组中任意一个重复的数字。
// 例如，如果输入长度为7的数组{ 2,3,1,0,2,5,3 }，那么对应的输出是第一个重复的数字2

int main()
{
	Solution a;

	int muns[] = { 2,3,1,0,2,5,3 };
	int num = 0;
	a.duplicate(muns, 7, &num);
	system("pause");
}

