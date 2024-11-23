#include <iostream> 
#include <vector>

using namespace std;
 
/*
								Динамический массив
-базовая структура данны, хкоторая может расширяться/сужаться.
-данные в нем хранятся последовательно
								 
	data = 0x00; size = 2; compacity = 4;
	индекы:		0x00 0x01 0x02 0x03
	массив:	.. | 5    2    _    _  | .. (.. -> чужая память)

Основные операции:
	1.  Индексация array[1] => *(data + 1 * size_type)
		"т.к data - указатель на начало массива то, чтобы обратитья к 1-му
		элементу прибавляю 1, а умножаю на size_type, для того чтобы перепрыгнуть!
		т.е ели у меня хранятьяс не однобайтовые, а двухбайтовые значения".
		Асимптотическая сложность O(1)

	2.  Вставка в начало это всегда свиг всех элементов массива.
		Чтобы вставить '1' в начало, я двигаю все элементы вправо.
		-массив:	.. | 1    5    2    _  | ..
		Сложность этой операции линейная O(n)
		-data = 0x00; size = 3; compacity = 4;

	3.  Вставка в конец - это O(1) но не всегда!
		Чтобы вставить '1' в начало, я двигаю все элементы вправо.
		-массив:	.. | 1    5    2    6  | ..
		-data = 0x00; size = 4; compacity = 4;

		-если мне нужно вставить в конец массива '3', а copacity = size,
		то в таком случае я создаю новый массив с copacity = 2 * size и 
		копирую туда свои элементы. НЕ ЗАБУДЬ ОЧИСТИТЬ ПАМЯТЬ СТАРОГО МАССИВА
		-новый массив:	.. | 1    5    2    6	3	_	_	_ | ..
		-data = OxAB; size = 5; compacity = 8;
		Асимптотическая сложность - армортизированная константа = O(1)*
		т.к иногда нам приходиться выделять память

	4.  Удаление элемента с конца. Могу обратиться к последнему и свободно удалить.
		Асимптотическая сложность = O(1)
		-новый массив:	.. | 1    5    2    6	_	_	_	_ | ..
		-data = OxAB; size = 4; compacity = 8;

	5.	Удаление элемента с начала. Удалим первый элемент:
		A) Сначала удаляю первый элемент .. | _    5    2    6	_	_	_	_ | ..
		B) Сдвигаю все элементы влево .. | 5    2    6	_	_	_	_	_ | ..
		Асимптотическая сложность = O(n)

		Однако, когда нам не важен порядок элементов в массиве, я могу 
		поменять местами первый с последним и удалить послежний.
		0) | 5    2    6	_	_	_	_	_ | ..
		1) | 6    2    5	_	_	_	_	_ | ..
		2) | 6    2    _	_	_	_	_	_ | ..

	6.  Если size * 4 == compacity => может прозойти уменьшение массива.
		БЫЛО: | 6    2    _	_	_	_	_	_ | ..
		СТАЛО: | 6    2    _	_ | ..
		-data = OxCC; size = 2; compacity = 4;
*/

int main()
{
	vector<int> data(4); // - пример динамического массива
	data[0] = 5; data[1] = 2;

	int second = *(data.begin() + 1); // получаю 2-й элемент массива

	data.insert(data.begin(), 1); // вставляю '1' в начало

	data.push_back(6); // O(1)
	data.push_back(3); // O(n)

	data.pop_back(); // удалил последний элемент
	
	data.erase(data.begin()); // удалил первый элемент
	swap(data[0], data[data.size() - 1]); // поменял эпервый с последним
	data.pop_back(); // удалил первый элемент
	


}
