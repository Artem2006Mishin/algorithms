#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Найти отрезок, максимальной длины, сумма элементов в котором не
превышает указанное кол-во
*/

int TwoPointer(vector<int> nums, int limit)
{
	int left = 0, right = 0, sum = 0, count = 0, max_count = 0;
	for (;right < nums.size(); right++)
	{
		sum += nums[right]; count++;
		while (sum > limit) {
			sum -= nums[left]; count--;
		}
		max_count = max(max_count, count);
	}

	return max_count;
}

int main()
{
	setlocale(LC_ALL, "RU");
	
	vector<int> a = { 1, 2, 2, 4, 5, 6, 2, 3 };
	int n = 10;
	
	cout << TwoPointer(a, n);
}
