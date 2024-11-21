#include <iostream> 
#include <vector>

using namespace std;

int ex1(int n) 
{
    for (int i = 0; i < n; i++) {
        cout << "Здорова" << " ";
        cout << "Артем" << endl;
    }
    for (int i = 0; i < n; i++) {
        cout << "Здорова" << " ";
        cout << "Максон" << endl;
    }
}
/*
Синтаксис O() - описывает только "скорость роста"
По этой причине константы отбрасываются: O(2n) -> O(n)
*/
