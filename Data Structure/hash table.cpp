#include <iostream>
#include <vector>
#include<list>

using namespace std;

template <typename K, typename V>
class HashTable {
private:
    vector<list<pair<K, V>>> table; // Массив связанных 
    //списков для цепочки из элементов
    size_t size; // Кол-во пар ключ-значение
    size_t capacity; // Емкость хеш-таблицы

    // Хеш-функция
    size_t hash(const K& key) const {
        // Отправляем ключ в черный ящик и получаем какое-то,
        // число которое мы еще раз хешируем: "Artem" => 1234 => 2
        return std::hash<K>{}(key) % capacity;
    }
public:
    // Конструктор
    HashTable(size_t capacity = 10) : capacity(capacity), size(0) {
        table.resize(capacity);
    }

    // Дектруктор
    ~HashTable() {
        clear();
    }

    void insert(const K& key, const V& value) {
        size_t index = hash(key);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                // Это цикл нужен если мы хоти обновить значение:
                // пара (5, 500) меняем на (5, 200)
                pair.second = value;
                return;
            }
        }
        // Добавляем пару
        table[index].push_back(make_pair(key, value));
        ++size;
    }

    // Поиск пары
    bool search(const K& key, V& value) const {
        size_t index = hash(key);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                // Пара есть
                value = pair.second;
                return true;
            }
        }
        // Пары нет
        return false;
    }

    // Удаление пары
    bool remove(const K& key) {
        size_t index = hash(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                --size;
                return true;
            }
        }

        return false;
    }

    // Function to clear the hash table
    void clear() {
        for (auto& list : table) {
            list.clear();
        }
        size = 0;
    }
 
    bool empty() const {
        return size == 0;
    }
   
    size_t getSize() const {
        return size;
    }
};

int main()
{
	
}
