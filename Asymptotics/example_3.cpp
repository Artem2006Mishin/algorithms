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

Доминирующие факторы отбрасывают второстепенные:
-если есть O(n^2 + n) = O(n^2)

Но это не означает, что в выражении не может быть суммы,
например, здесь затраты по времени: O(n + m)
*/

int sum(vector<int> one, vector<int> two) 
{
    int res = 0;
    for (auto n : one) {
        res += n;
    }
    for (auto n : two) {
        res += n;
    }
    return res;
}
