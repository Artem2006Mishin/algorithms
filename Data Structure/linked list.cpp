#include <iostream>  

using namespace std;

/*
                                            Связаный список

-схожая структура данных с динамическим массивом
-главное отличие заключается в том, что элементы в нем
 хранятся неупорядочено

пример связанного спика:
   0xAC        0x12        0x03
 |3|0x12| -> |1|0x03| -> |5|null| -> null
   Head       Tail

-помимо данных мы храним еще указатель на следующий элемент связанного списка
-чтобы описать отдельное звено связанного списка мы можем использовать структуру:
*/

struct Node
{
    int value;
    Node* next;
    Node(int n) : value(n), next(nullptr) {}
};

/*
-чтобы вставить элемент в НАЧАЛО связанного списока я могу создать новое звено,
 установив значение next равное первому элементу старого списка:

   0xBC    0xAC        0x12        0x03
 |4|0xAC| -> |3|0x12| -> |1|0x03| -> |5|null| -> null
   Head          Tail

-чтобы удалить звено из НАЧАЛА надо просто удалить :-) 
-O(1) будет только в случае с двусвязанными списками!

    0xAC        0x12        0x03
  |3|0x12| -> |1|0x03| -> |5|null| -> null
    Head       Tail

-аналогичные операции происходят с добавление и удалением из конца и с середины,
 только в случае сс серединой мы обновляем сразу 2 соседних звена.
-вставка, удаление имеет константную сложность O(1) во всех случаях.

-Операция индексирования в связанном списке будет выполнять за
    O(n): мы будем перебирать звенья пока не встретим нужное!
-В этом минус списков и плюс динамических массивов, т.к за счет
    того упорядоченности мы легко обратимся к нужному элементу
*/

int main()
{
    // создание звеньев 
    Node first(10);
    Node second(20);
    Node third(30);

    // добавление связи 
    first.next = &second;
    second.next = &third;
    third.next = nullptr;

    // вставка x в конец
    Node x(777);
    x.next = nullptr;
    third.next = &x;

    // вывод 
    Node* iter = &first;
    while (iter != nullptr) {
        cout << iter->value << " ";
        iter = iter->next;
    }
    cout << endl;

    // удалить 
   
    third.next = nullptr;
    /*
     Node* p = &x;    
    delete p;
    КАК ЭТО УДАЛИТЬ ВОПРОС!
    */

    Node* iter1 = &first;
    while (iter1 != nullptr) {
        cout << iter1->value << " ";
        iter1 = iter1->next;
    }
}
