#include <iostream>  
using namespace std;

typedef long long ll;
constexpr ll MAX_N = 1'000'006;
ll input_array[MAX_N];
ll segment_tree[MAX_N * 4];

// i - индекс элемента дерева отрезков, который мы хотим сейчас вычислить
// right, left - диапазон оригинального массива, который охватывает элемент
// дерева отрезков с индексом i

void build_tree(int i, int left, int right) {
    if (right == left) {
        segment_tree[i] = input_array[right];
    }
    else {
        int mid = (left + right) / 2;
        build_tree(i * 2, left, mid);
        build_tree(i * 2 + 1, mid + 1, right);
        segment_tree[i] = segment_tree[i * 2] + segment_tree[i * 2 + 1];
    }
}

// i - индекс текущего элемента дерева отрезков
// right, left - диапазон исходного массива, который охватывает элемент
// дерева отрезков c индексом i
// update_index - индекс заменяемого элемента исходного массива
// value - заменяемое значение

void update_tree(int i, int left, int right, int update_index, int value) {
    if (left == right)
        segment_tree[i] = value;
    else {
        int mid = (left + right) / 2;
        if (update_index <= mid)
            update_tree(i * 2, left, mid, update_index, value);
        else
            update_tree(i * 2 + 1, mid + 1, right, update_index, value);
        segment_tree[i] = segment_tree[i * 2] + segment_tree[i * 2 + 1];
    }
}

// i - индекс текущего элемента дерева отрезков
// right, left - диапазон исходного массива, который охватывает элемент
// дерева отрезков c индексом i
// input_left, input_right - диапазон исходного массива, на котором необходимо
// найти сумму

ll sum_on_range(int i, int left, int right, int input_left, int input_right) {
    if (input_left > input_right)
        return 0;
    if (left == input_left && right == input_right)
        return segment_tree[i];
    int mid = (left + right) / 2;
    int left_son = sum_on_range(i * 2, left, mid, input_left, std::min(mid, input_right));
    int right_son = sum_on_range(i * 2 + 1, mid + 1, right, std::max(mid, input_left), input_right);
    segment_tree[i] = left_son + right_son;
    return left_son + right_son;
}

int main()
{

}

