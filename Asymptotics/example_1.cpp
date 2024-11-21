#include <iostream> 
#include <vector>

using namespace std;

// лучший случай O(1) 
int linear_search(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, 1);

// худший случай O(n)
int linear_search(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9}, 9);

int linear_search(vector<int> nums, int target) 
{
    /*
    кол-во операций : 1 + 3n; где n - кол-во чисел в массиве.
    если их будет миллиард, то единички особо не повлияют, поэтому их можно отбросить,
    даже 3 можно принебречь, поэтому результат: n

    1. инициализация (int i = 0)
    2. сравнение (i < nums.size())
    3. инкремент (i++)
    4. условие (if (nums[i] == target))

    Для большинства случаев худший совпадает с ожидаемым!
    */ 
        
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == target)
            return i;
    }
    return -1;
}

