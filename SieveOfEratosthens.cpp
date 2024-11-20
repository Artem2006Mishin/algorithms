#include <iostream>
#include <vector>

using namespace std;

vector<int> SieveOfEratosthens(int n)
{
	vector<bool> prime(n + 1, true);
	vector<int> ans;

	for (int p = 2; p <= n; p++)
	{
		if (prime[p])
		{
			for (int i = p * p; i <= n; i += p)
			{
				prime[i] = false;
			}
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (prime[i]) {
			ans.push_back(i);
		}		
	}

	return ans;
}

int main()
{
	setlocale(LC_ALL, "RU");
	
	int n = 30;
	vector<int> a = SieveOfEratosthens(n);
	for (auto i : a)
	{
		cout << i << " ";
	}
	
}
