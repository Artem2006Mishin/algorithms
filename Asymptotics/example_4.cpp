#include <iostream> 
#include <vector>

using namespace std;

/*
Когда динамический массив заполняется, класс создает новый 
массив двойной емкости и копирует все элементы в новый массив.
Как же оценить время вставки?
-Если массив заполнен, то вставка нового элемента будет 
выполнятся за O(n), т.к необходимо создать новый массив и 
скопировать туда n элеметнов, поэтому вставка в данном 
случае займет время O(n) 
-Заполнение массива происходит редко. Если массив не заполнен, 
то вставка осуществляется за O(1)
*/

int main()
{
    vector<int> nums; // size = 0, capacity = 0
    nums.push_back(1); // size = 1, capacity = 1
    nums.push_back(1); // size = 2, capacity = 2
    nums.push_back(1); // size = 3, capacity = 4
    nums.push_back(1); // size = 4, capacity = 4
    nums.push_back(1); // size = 5, capacity = 8
    nums.push_back(1); // size = 6, capacity = 8
    nums.push_back(1); // size = 7, capacity = 8
    nums.push_back(1); // size = 8, capacity = 8
    nums.push_back(1); // size = 9, capacity = 16

// Таким образом емкость массива удваивается при
// размерах: 1, 2, 4, 8, 16, 32, 64, 128 ...  
}
