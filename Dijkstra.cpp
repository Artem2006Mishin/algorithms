#include <iostream> 

using std::cout;
using std::cin;
using std::endl;

int main()
{
    setlocale(LC_ALL, "RU");

    const int SIZE = 6;
    int a[SIZE][SIZE], v[SIZE], d[SIZE];
    int temp, minindex, min, begin_index = 0;

    for (int i = 0; i < SIZE; i++)
    {
        d[i] = 10'000;
        v[i] = 1;
        a[i][i] = 0;
        for (int j = i + 1; j < SIZE; j++)
        {
            cout << "Введите значение для " << i + 1 << "-" << j + 1 << ": ";
            cin >> temp;
            a[i][j] = temp;
            a[j][i] = temp;
        }
    }
    d[begin_index] = 0;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    do {
        minindex = 10000;
        min = 10000;
        for (int i = 0; i < SIZE; i++)
        {
            if ((v[i] == 1) && (d[i] < min))
            {
                min = d[i];
                minindex = i;
            }
        }

        if (minindex != 10000)
        {
            for (int i = 0; i < SIZE; i++)
            {
                if (a[minindex][i] > 0)
                {
                    temp = min + a[minindex][i];
                    if (temp < d[i])
                    {
                        d[i] = temp;
                    }
                }
            }
            v[minindex] = 0;
        }
    } while (minindex < 10000);

    for (int i = 0; i < SIZE; i++) {
        cout << d[i] << " ";
    }
}
