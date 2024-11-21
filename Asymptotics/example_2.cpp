#include <iostream> 
#include <vector>

using namespace std;

/*
Этот алгоритм использует линейная сложность как по скорости, так и 
по памяти O(n)
*/
vector<int> modify(vector<int> nums) {
    vector<int> res(nums.size());
    for (int i = 0; i < nums.size(); i++) {
        res[i] = nums[i] * 2;
    }
    return res;
}

// А это уже стек:
int sum(int n) {
    if (n <= 0)
        return 0;
    else
        return n + sum(n - 1);
}
/*
Каждый вызов добавляет новый уровень в стек, 
поэтому затраты по памяти O(n):
sum(4)
    sum(3)
        sum(2)
            sum(1)
                sum(0)
*/


// Но тем не менее, наличие n вызовов функции не подразумевает
// затрат по памяти O(n):
int pair_sum(int a, int b)
{
    return a + b;
}

int pair_sum_sequence(int n) 
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += pair_sum(i, i + 1);
    }
    return sum;  
        
}
/*
Всего будет сделано O(n) вызовов pair_sum, однако
эти вызовы не размещаются в стеке одновременно, поэтому
затраты по памяти O(1)
*/
